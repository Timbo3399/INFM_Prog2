# C/C++ Code Style Enforcement
### Based on: Hochschule Offenburg – C/C++ Coding Style Guide V3.0.12

This repository automatically checks all C/C++ code against the coding style guide
using GitHub Actions on every push and pull request.

---

## What gets checked automatically

| Tool | Rules covered |
|---|---|
| **clang-format** | CL1–CL6, A1 (indentation, braces, spacing) |
| **cppcheck** | DV13–DV19, F13, K rules (static analysis, null checks, type mismatches) |
| **check_style.py** | A4, A6, A7, DV4, DV8–DV10, K1, K2, K5, K8, K11, F4, P2, P3 |

---

## Setup: Add these files to your repository

```
your-repo/
├── .editorconfig                        ← Editor formatting (A1)
├── .clang-format                        ← Auto-formatter config (CL1–CL6)
├── .github/
│   ├── copilot-instructions.md          ← GitHub Copilot reads this automatically
│   ├── workflows/
│   │   └── style-check.yml             ← GitHub Actions CI pipeline
│   └── scripts/
│       └── check_style.py              ← Custom rule checker (Python, no dependencies)
└── README_STYLE.md                      ← This file
```

Copy all files into your repository root and push. GitHub Actions starts automatically.

---

## Fix formatting locally

**Auto-fix formatting** (clang-format):
```bash
# Fix a single file
clang-format --style=file -i src/MyModule.c

# Fix all C/C++ files at once
find . -name "*.c" -o -name "*.h" -o -name "*.cpp" | xargs clang-format --style=file -i
```

**Run cppcheck locally:**
```bash
cppcheck --enable=all --std=c99 src/
```

**Run the custom checker locally:**
```bash
python3 .github/scripts/check_style.py
```

---

## GitHub Copilot integration

The file `.github/copilot-instructions.md` is automatically read by GitHub Copilot
in VS Code and on GitHub. It contains all style guide rules in plain English so
Copilot will suggest compliant code.

**In VS Code:** Install the GitHub Copilot extension. Copilot reads
`copilot-instructions.md` automatically from your repo.

**Ask Copilot to fix your code:**
> "Fix this function to comply with our coding style guide."
> "Rename these variables using Hungarian notation as defined in the style guide."
> "Split this function so it has at most 40 lines."

---

## Editor setup (A1 – 3 spaces, no tabs)

The `.editorconfig` file configures most editors automatically.
Install the EditorConfig plugin for your editor if needed:
- **VS Code:** [EditorConfig for VS Code](https://marketplace.visualstudio.com/items?itemName=EditorConfig.EditorConfig)
- **CLion / IntelliJ:** built-in support
- **Vim/Neovim:** `editorconfig-vim` plugin

---

## Limitations

Some rules require human review and cannot be automatically enforced:

| Rule | Description |
|---|---|
| A2 | English language in comments/names |
| A3 | Comment density (10–30%) |
| A12 | Meaningful names |
| F3 | Parameter names in declarations |
| F6 | Max 3 parameters |
| F7 | Cyclomatic complexity ≤ 10 (use `cppcheck --enable=style` or Testwell CMT++) |
| K4 | Fallthrough documentation |
| K7 | Ternary operator comments |

For cyclomatic complexity (F7 / v(G)), use:
```bash
cppcheck --enable=style --template="{file}:{line}: {severity}: {message}" src/
```
or the **Testwell CMT++** tool as specified in the style guide.
