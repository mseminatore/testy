# testy - Copilot Instructions

## What this project is

`testy` is a minimal single-header C/C++ test framework. Users integrate it by including `test.h` and linking `test_main.c` into their project.

## Build and test

**Using Make:**
```sh
make          # builds example_test binary
./example_test  # run tests
make clean
```

**Using CMake:**
```sh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
cd build && ctest   # run via CTest
```

Running a single test binary directly (e.g. after `make`):
```sh
./example_test
```

## Architecture

The framework has two files to integrate:

- **`test.h`** — The only include needed. Defines all macros (`TEST`, `TESTEX`, `SUITE`, `MODULE`, etc.) and declares the global counters and `test_main()` prototype.
- **`test_main.c`** — Provides `main()`, initializes the console (VT100 support on Windows), calls `BEGIN_TESTS()`, dispatches to `test_main()`, then calls `END_TESTS()`. Also defines global counters: `test_number`, `test_failures`, `test_suites`, `test_modules`.

The **user implements `test_main(int argc, char *argv[])`** — not `main()`. The library owns `main()`.

Test hierarchy: `MODULE` > `SUITE` > `TEST`/`TESTEX`. `END_TESTS()` returns the failure count, so `main()` returns 0 on full pass, or N (number of failures) otherwise — enabling CTest and CI integration.

## Key conventions

- Tests are grouped with `MODULE("name")` at the top level, then `SUITE("name")` for sub-groups, then individual `TEST(pred)` or `TESTEX("msg", pred)` calls.
- `SKIP_TEST(msg)` marks a test as skipped (printed in yellow, counted separately, not a failure)
- Floating-point comparisons use `EQUAL_EPSILON(a, b)` (threshold: `1e-5`; override by defining `EPSILON` before including `test.h`).
- Array comparisons use `EQUAL_ARRAY(a, b)` / `NOT_EQUAL_ARRAY(a, b)` (backed by `memcmp` on `sizeof(a)`).
- In larger test files, encapsulate suites in `static void test_foo()` helper functions called from `test_main()`.
- Define `TESTY_NO_COLOR` before including `test.h` to disable all ANSI color output (useful for log files or CI environments that strip escape codes); `CHECK_MARK`/`X_MARK` become plain `PASS`/`FAIL`.
- `TRUE` and `FALSE` are defined if not already present.
- `ARRAY_SIZE(a)` is provided for array length.
