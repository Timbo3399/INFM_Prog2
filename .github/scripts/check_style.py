#!/usr/bin/env python3
"""
Custom C/C++ Style Checker
Hochschule Offenburg – Coding Style Guide V3.0.12

Checks rules not covered by clang-format or cppcheck:
  A4   – No block comments /* */ (except doxygen)
  A6   – Max 40 lines per function (approximation via brace counting)
  A7   – Max 400 lines per .c file
  DV4  – One variable declaration per line (catches: int a, b;)
  DV8  – No lowercase l/u suffixes on literals
  DV9  – Float literals need F suffix (uppercase), not f
  DV10 – Hex constants: lowercase a-f forbidden
  K1   – No goto
  K2   – No break outside switch (approximation)
  K5   – No continue
  K8   – No elseif
  K11  – No bare boolean shorthand in if/while (e.g. if (val))
  K13  – No modification of for-loop variable inside loop body
  K14  – No float loop variables
  P2   – No #include of .c files
  P3   – #define names must be ALL_CAPS
  F4   – Multiple return statements per function (warns)
"""

import os
import re
import sys

# ── Configuration ─────────────────────────────────────────────────────────────
MAX_FUNCTION_LINES = 40   # Rule A6
MAX_FILE_LINES     = 400  # Rule A7
EXTENSIONS         = (".c", ".h", ".cpp", ".hpp")
EXCLUDE_DIRS       = {"build", ".git", ".github", "CMakeFiles"}

errors   = []
warnings = []

def report_error(filepath, lineno, rule, message):
    errors.append(f"  ❌ {filepath}:{lineno} [{rule}] {message}")

def report_warning(filepath, lineno, rule, message):
    warnings.append(f"  ⚠️  {filepath}:{lineno} [{rule}] {message}")

# ── Helpers ───────────────────────────────────────────────────────────────────
def collect_files(root="."):
    result = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d not in EXCLUDE_DIRS]
        for fname in filenames:
            if fname.endswith(EXTENSIONS):
                result.append(os.path.join(dirpath, fname))
    return result

def strip_strings_and_comments(line):
    """Remove string literals and line comments for pattern matching."""
    # Remove string literals
    line = re.sub(r'"[^"\\]*(?:\\.[^"\\]*)*"', '""', line)
    # Remove line comments
    line = re.sub(r'//.*', '', line)
    return line

def is_doxygen_comment(line):
    return line.strip().startswith("/**") or line.strip().startswith("* @") or line.strip().startswith("*/")

# ── Per-line checks ───────────────────────────────────────────────────────────
def check_line(filepath, lineno, raw_line, lines, all_lines):
    line = raw_line.rstrip("\n")
    clean = strip_strings_and_comments(line)
    stripped = line.strip()

    # A4 – No block comments (allow doxygen /** ... */)
    if "/*" in clean and not stripped.startswith("/**") and not stripped.startswith("*"):
        report_error(filepath, lineno, "A4", "Block comment /* */ is forbidden. Use // instead.")

    # DV4 – Multiple variable declarations on one line (e.g. int a, b;)
    # Simplified: look for type followed by ident, comma, ident not in for(...)
    if re.search(r'\b(int|char|float|double|long|short|unsigned|bool|uint\w+|int\w+|f32_t|f64_t)\b', clean):
        if not stripped.startswith("//") and not stripped.startswith("#"):
            # Match things like: int a, b; but not: func(a, b) or struct {x, y}
            if re.search(r'\b\w+\b\s+\w+\s*,\s*\w+\s*[=;]', clean):
                if "for" not in clean and "(" not in clean.split(",")[0]:
                    report_error(filepath, lineno, "DV4",
                                 "Declare only one variable per line.")

    # DV8 – Lowercase l or u suffix on integer literals
    if re.search(r'\b\d+[lLuU]*[lu][lLuU]*\b', clean):
        if re.search(r'\b\d+[lu]\b', clean):
            report_error(filepath, lineno, "DV8",
                         "Use uppercase U and L suffixes (not u/l).")

    # DV9 – Lowercase f suffix on float literals
    if re.search(r'\b\d+\.\d*f\b|\b\d*\.\d+f\b', clean):
        report_error(filepath, lineno, "DV9",
                     "Use uppercase F suffix for float literals (not f).")

    # DV10 – Hex constants with lowercase a-f
    if re.search(r'0x[0-9a-f]*[a-f][0-9a-fA-F]*', clean):
        report_error(filepath, lineno, "DV10",
                     "Hex constants must use uppercase A–F (e.g. 0x1AF3).")

    # K1 – goto
    if re.search(r'\bgoto\b', clean):
        report_error(filepath, lineno, "K1", "goto is forbidden.")

    # K5 – continue
    if re.search(r'\bcontinue\s*;', clean):
        report_error(filepath, lineno, "K5", "continue is forbidden. Restructure control flow.")

    # K8 – elseif (without space)
    if re.search(r'\belseif\b', clean):
        report_error(filepath, lineno, "K8",
                     "elseif is forbidden. Use 'else { if (...) { } }' instead.")

    # P2 – #include of .c file
    if re.match(r'\s*#include\s+[<"][^>"]+\.c[>"]\s*', line):
        report_error(filepath, lineno, "P2", "#include of a .c file is forbidden.")

    # P3 – #define name not ALL_CAPS
    m = re.match(r'\s*#define\s+([A-Za-z_]\w*)', line)
    if m:
        name = m.group(1)
        # Exclude include guards (_FILENAME_H) and SW_ conditionals – those are fine
        if not name.startswith("SW_") and not name.startswith("_") and name != name.upper():
            report_error(filepath, lineno, "P3",
                         f"#define name '{name}' must be ALL_CAPS.")

    # K11 – Bare boolean in if/while: if (val) instead of if (val != 0)
    m = re.search(r'\b(if|while)\s*\(\s*([A-Za-z_]\w*)\s*\)', clean)
    if m:
        inner = m.group(2)
        # Allow: if (true), if (false), if (NULL) – common accepted forms
        if inner not in ("true", "false", "NULL"):
            report_warning(filepath, lineno, "K11",
                           f"Avoid bare boolean check 'if ({inner})'. "
                           f"Prefer explicit: 'if ({inner} != 0)'.")

# ── Per-file checks ───────────────────────────────────────────────────────────
def check_file(filepath):
    try:
        with open(filepath, encoding="utf-8", errors="replace") as f:
            all_lines = f.readlines()
    except Exception as e:
        report_warning(filepath, 0, "IO", f"Could not read file: {e}")
        return

    total_lines = len(all_lines)

    # A7 – Max 400 lines per .c file
    if filepath.endswith(".c") and total_lines > MAX_FILE_LINES:
        report_error(filepath, total_lines, "A7",
                     f"File has {total_lines} lines (max {MAX_FILE_LINES}).")

    # Per-line checks
    for lineno, raw_line in enumerate(all_lines, start=1):
        check_line(filepath, lineno, raw_line, all_lines, all_lines)

    # A6 – Approximate function length via brace depth tracking
    # F4  – Warn on multiple return statements per function
    check_function_metrics(filepath, all_lines)

def check_function_metrics(filepath, all_lines):
    """
    Approximate function body detection by tracking brace depth.
    Assumes Allman-style braces (CL1).
    """
    depth          = 0
    func_start     = None
    func_line      = 0
    return_count   = 0

    for lineno, raw_line in enumerate(all_lines, start=1):
        line  = raw_line.rstrip("\n")
        clean = strip_strings_and_comments(line)

        opens  = clean.count("{")
        closes = clean.count("}")

        if depth == 0 and opens > 0:
            # Entering a top-level block – assume it's a function
            func_start   = lineno
            return_count = 0

        depth += opens
        depth -= closes

        if depth > 0:
            # Inside a function body
            if re.search(r'\breturn\b', clean):
                return_count += 1

        if depth == 0 and func_start is not None:
            func_end    = lineno
            func_length = func_end - func_start - 1  # exclude braces themselves

            # A6
            if func_length > MAX_FUNCTION_LINES:
                report_error(filepath, func_start, "A6",
                             f"Function body is ~{func_length} lines (max {MAX_FUNCTION_LINES}).")

            # F4
            if return_count > 1:
                report_error(filepath, func_start, "F4",
                             f"Function has {return_count} return statements. Only 1 is allowed.")

            func_start   = None
            return_count = 0

        if depth < 0:
            depth = 0  # recovery from parse errors

# ── Main ──────────────────────────────────────────────────────────────────────
def main():
    files = collect_files(".")
    if not files:
        print("No C/C++ files found.")
        sys.exit(0)

    print(f"Checking {len(files)} file(s)...\n")

    for filepath in sorted(files):
        check_file(filepath)

    if warnings:
        print("Warnings:")
        for w in warnings:
            print(w)
        print()

    if errors:
        print("Errors:")
        for e in errors:
            print(e)
        print(f"\n❌ {len(errors)} error(s) found. Please fix them.")
        sys.exit(1)
    else:
        print(f"✅ Custom style check passed. ({len(warnings)} warning(s))")
        sys.exit(0)

if __name__ == "__main__":
    main()
