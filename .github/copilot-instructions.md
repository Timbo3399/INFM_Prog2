# C/C++ Coding Style Guide – Hochschule Offenburg (V3.0.12)

This file defines the mandatory coding standards for all C/C++ code in this repository.
GitHub Copilot must follow these rules when suggesting or generating code.

---

## General Rules (A)

- **A1** – Use 3 spaces per indentation level. Never use actual tab characters.
- **A2** – All source code (comments, variable names, function names) must be written in **English**.
- **A3** – Comment density: 1–3 comment lines per 10 lines of code (10–30%). Do not document trivial code.
- **A4** – Use only `//` comments. Multi-line `/* */` comments are **forbidden** (exception: doxygen).
- **A5** – Split projects into multiple `*.c` and `*.h` files. Filenames start with an uppercase letter.
- **A6** – A function must contain between **4 and 40** lines of code (LOCpro).
- **A7** – A `.c` file must contain between **4 and 400** lines.
- **A8** – File structure order:
  1. System headers (`#include <stdio.h>`)
  2. User headers (`#include "MyModule.h"`)
  3. Module-specific types (defines, constants, enums, structs, typedefs, macros)
  4. External/global variables (exception only)
  5. Function declarations (all except `main`)
  6. Function implementations (`main` is always first)
- **A9 (II)** – No project- or module-global variables. Define in `main` and pass via call-by-reference.
- **A9 (ES)** – Minimize global variables. Use `volatile` to prevent unwanted compiler optimization.
- **A10 (ES)** – Project-global variables must be defined in a `.c` file.
- **A11** – Encapsulate global variables using getter/setter functions with validation.
- **A12** – Use meaningful, self-documenting names for all variables, types, and functions.
- **A13** – Set the **highest compiler warning level** (e.g. `/W4` in MSVC, `-Wall` in GCC).
- **A14** – **Treat all warnings as errors** (`/WX` in MSVC, `-Werror` in GCC).

---

## Code Layout (CL)

- **CL1** – Opening `{` and closing `}` braces always start on a **new line**.
- **CL2** – Indent code blocks inside braces by **3 spaces**.
- **CL3** – Add a space after keywords: `if`, `while`, `for`, `switch`.
- **CL4** – No space between a function name and its opening parenthesis: `MyFunc()` not `MyFunc ()`.
- **CL5** – No spaces around primary operators (`()`, `->`, `.`, `[]`) or unary operators.
  Add one space around: relational (`<`, `>`, `==`, `!=`), arithmetic (`+`, `-`, `*`, `/`, `%`), logical (`&&`, `||`), bitwise (`&`, `|`, `^`, `<<`, `>>`), and assignment operators (`=`).
- **CL6** – Braces `{}` for `switch`, `while`, `for`, `do/while`, `if`, `else` align under the first letter of the keyword.

---

## Data Types, Variables, Constants (DV)

- **DV1** – Variables and constants use **self-documenting English names** starting with uppercase, prefixed with a Hungarian notation type prefix (see DV3).
- **DV2 (ES)** – Use `stdint.h` typedefs instead of native types: `uint8_t`, `int32_t`, `f32_t`, etc.
- **DV3 (II)** – Hungarian Notation prefixes:
  | Prefix | Type |
  |--------|------|
  | `i`    | `int` |
  | `ui`   | `unsigned int` |
  | `si`   | `short int` |
  | `usi`  | `unsigned short int` |
  | `li`   | `long int` |
  | `uli`  | `unsigned long int` |
  | `lli`  | `long long int` |
  | `ulli` | `unsigned long long int` |
  | `f`    | `float` |
  | `d`    | `double` |
  | `ld`   | `long double` |
  | `c`    | `signed char` |
  | `uc`   | `unsigned char` |
  | `b`    | `_Bool` / `bool` |
- **DV3 (ES)** – Prefix with type shorthand: `u8`, `s16`, `u32`, `s32`, `f32`, `f64`, etc.
- **DV4** – Declare only **one variable per line**.
- **DV5** – Attach `*` to the type, not the name: `int* piVal` not `int *piVal`.
- **DV6** – Prefix constants with `c`, pointers with `p`, arrays with `a`, void pointers with `pv`.
- **DV7** – Loop counter variables may use `i`, `j`, `k`, `l`, `m`, `n` as exception.
- **DV8** – Suffix: `L` for long, `U` for unsigned, `UL` for unsigned long. No lowercase `u` or `l`.
- **DV9** – Float literals use `F` suffix (uppercase). Always have digit before and after decimal point. Example: `3.1415F`, `0.618F`.
- **DV10** – Hex constants: `0x` prefix, uppercase A–F. Example: `0x1AF3`.
- **DV11** – Avoid octal constants (leading `0`).
- **DV12** – Always specify base type with modifiers: `long int`, not just `long`.
- **DV13** – Avoid implicit casts. Always use explicit casts: `iVal = (int)fVal;`
- **DV14** – Initialize pointers to `NULL` before first use if no valid address is assigned immediately.
- **DV15** – Use `sizeof` with `malloc`, never hardcoded sizes. Cast result explicitly in C++.
- **DV16** – After `free()`, set pointer to `NULL`.
- **DV17** – Avoid embedded assignments (e.g. in `if` conditions). Split into separate statements.
- **DV18** – Never mix signed and unsigned variables in the same expression/condition.
- **DV19** – Never apply bitwise shift operators (`>>`, `<<`) to signed variables.

---

## Complex Data Types (KD)

- **KD1** – Prefix for complex type variables: `e` (enum), `u` (union), `s` (struct), `bf` (bitfield).
- **KD2** – Also apply `c` (const), `a` (array), `p` (pointer) prefixes to complex types.
- **KD3** – Always define a `typedef` and a pointer typedef for each complex type. Postfix: `_t`.
- **KD4** – Postfix `_t` for all custom typedefs.
- **KD5** – Never access bitfield elements via bitmasks.
- **KD6** – Bitfield elements must be `unsigned int` (II) or `uint32_t` (ES).
- **KD7** – Always specify the starting value for the first enum element (even if 0).
- **KD8** – Always use `typedef` for function pointers.

---

## Functions (F)

- **F1** – Declare all local variables at the top of the function body, one per line, always initialized.
- **F2** – Declare functions before calling them.
- **F3** – Include parameter names in function declarations. Use `void` if no parameters.
- **F4** – Only **one `return`** statement per function, as the last statement.
- **F5** – `void` functions have **no `return`** statement.
- **F6** – Maximum **3 parameters** per function.
- **F7** – Maximum **9 conditions** per function (cyclomatic complexity ≤ 10).
- **F8** – Mark read-only parameters as `const`.
- **F9 (ES)** – Never pass structs by value. Always pass by pointer.
- **F10** – Functions used only within a module must be declared `static`.
- **F11 (II)** – Function names: Verb + specifying words in English, each starting with uppercase. Common verbs: `Get`, `Set`, `Init`, `Delete`, `Print`, `Is`.
- **F11 (ES)** – Function names: `<ReturnPrefix><ModuleName>_<Verb><Words>`. Example: `u32PWM_GetSignalGPIO()`.
- **F12** – `main` is always the first function in `Main.c`.
- **F13** – Always perform NULL check (sanity check) at the start of functions that receive pointers.

---

## Control Structures (K)

- **K1** – `goto` is **forbidden**.
- **K2** – `break` is only allowed in `switch/case`.
- **K3** – Every `switch/case` must have a `default` case with a `break`.
- **K4** – Fallthroughs in `switch/case` must be explicitly documented with a comment.
- **K5** – `continue` is **forbidden**. Restructure the control flow instead.
- **K6** – `exit()` only in genuine emergency/safety situations.
- **K7** – Avoid the ternary operator `?:` when an `if-else` is clearer. Always add a comment if used.
- **K8** – `elseif` is **forbidden**. Use `else { if (...) { } }` instead.
- **K9** – Always use braces `{}` even for single-line code blocks.
- **K10** – Follow structured programming rules: one entry/exit per function, no jumping into/out of loops or conditions.
- **K11** – Avoid shorthand boolean checks. Write `if (iVal != 0)` not `if (iVal)`.
- **K12** – Use `for` loops when iteration count is known in advance.
- **K13** – Never modify the loop variable inside a `for` loop body.
- **K14** – Never use floating point variables as loop counters.
- **K15** – Never compare floating point variables with `==`. Use a tolerance-based comparison instead.

---

## Preprocessor (P)

- **P1** – Every header file must have an include guard: `#ifndef _FILENAME_H / #define _FILENAME_H / #endif`.
- **P2** – Never `#include` a `.c` file.
- **P3** – `#define` names are always ALL_CAPS.
- **P4** – Conditional compilation defines use `SW_` prefix: `#define SW_LINUX`.
- **P5** – Macros: wrap entire macro and every parameter in parentheses, cast to correct types.
- **P6** – Split long macros across multiple lines using backslash `\`.
- **P7** – Prefer `inline` functions over macros for type safety.
- **P8** – Prefer `const` variables over `#define` for symbolic constants.
- **P9** – Preprocessor directives always start at column 1.

---

## C++ Specific Rules

- **CPPA1** – Use ES naming conventions (DV3 ES, F11 ES).
- **CPPA2** – Prefix references with `r`: `uint32_t& ru32Val`.
- **CPPA3** – Always use namespaces. Access with qualified names (`std::cout`).
- **CPPA4** – Use C++ standard library headers: `<cstring>` not `<string.h>`.
- **CPPA5** – Prefer range-based `for` loops.
- **CPPA7** – Prefix structs with `s`, unions with `u`, enums with `e`.
- **CPPA8** – Use scoped enums: `enum class eColors { Red, Blue };`.
- **CPPA9** – Initialize objects with braces only: `Car myCar { 130U };`.
- **CPPA10** – Use `auto` where appropriate; prefix auto variables with `a`.

### Classes (CPPK)

- **CPPK1** – Class member order: `public` → `protected` → `private`. Class names start with uppercase. Attributes should be `private`.
- **CPPK3** – Attribute names end with `_`. Class (static) variables end with `_c`.
- **CPPK4** – Mark used default constructors/destructor with `= default`.
- **CPPK5** – Mark deleted constructors/destructor with `= delete`.
- **CPPK6** – Use C++ casts (`static_cast`, `dynamic_cast`, etc.).
- **CPPK7** – Mark non-mutating methods as `const`.
- **CPPK8** – Always apply RAII.
- **CPPK9** – Destructor should always be `virtual`.
- **CPPK10** – Mark non-throwing functions with `noexcept`.
