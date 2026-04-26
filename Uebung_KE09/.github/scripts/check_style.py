#!/usr/bin/env python3
import os
import re

root = '.'
max_line_length = 80
indent_size = 3
errors = []

for dirpath, dirnames, filenames in os.walk(root):
    for fn in filenames:
        if fn.endswith(('.c', '.h')):
            path = os.path.join(dirpath, fn)
            with open(path, 'r', encoding='utf-8') as f:
                for i, line in enumerate(f, 1):
                    if '\t' in line:
                        errors.append(f"{path}:{i}: Tab character found")
                    if len(line.rstrip('\n')) > max_line_length:
                        errors.append(f"{path}:{i}: Line exceeds {max_line_length} chars")
                    # check indentation
                    m = re.match(r"^( +)\S", line)
                    if m:
                        if len(m.group(1)) % indent_size != 0:
                            errors.append(f"{path}:{i}: Indent not multiple of {indent_size}")

for e in errors:
    print(e)

if errors:
    raise SystemExit(1)
