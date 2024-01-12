# testy is a simple test framework

As a software developer I found that I knew little about test frameworks. 
Like many developers I all too often relied on others to test my code.
I have many projects which I revisit periodically. In order to minimize the
chances of introducing new bugs into old code bases I decided that I needed
to build up a collection of unit tests.

To do that, I needed to learn about Unit testing and choose a framework. I
explored many of the available testing frameworks. What I found was that, 
while very capable, many were much larger and more complex than my simple and
straightforward needs.

The `testy` framework attempts to offer a reasonable balance between 
testing functionality and complexity. I've used this now for several projects
and am sharing it in the hopes that it may be useful to others.

> Note: If your console supports VT100 terminal congtrol escape sequences then the 
> output will use color highlighting.

# testy examples

Integrating and using testy is meant to be very simple. There is only one 
header file to include `test.h` in your project. And there is only one C file
to add to your project `test_main.c`. The `main()` function is implemented in
`test_main.c` and calls your code which starts with `test_main()`.

The test framework provides a number of simple but useful macros. They are:

Macro | Description
----- | -----------
COMMENT(str) | outputs a comment in test output
MODULE(str) | name the start of a new module
SUITE(str) | name the start of a new test suite
TEST(pred) | assert-like test case, outputs pred as text
TEXTEX(msg, pred) | assert-like test of pred, outputs msg as text
EQUAL_ARRAY(a, b) | tests for equality of two arrays using memcmp
NOT_EQUAL_ARRAY(a, b) | tests for inequality of two arrays
EQUAL_EPSILON(a, b) | tests that fabs(a - b) > epsilon

Below is a simple example of usage.

```c
#include "test.h"

void test_main(int argc, char *argv[]) {
    // define a module
    MODULE("Sample test");

    // define a test suite
    SUITE("Basic");

    // display a comment
    COMMENT("test addition...");

    // execute some unit tests
    TEST(((1 + 1) == 2));
    TESTEX("This test fails", 0);
}

```

And here is the output from running the example code above.

```
Begin test pass...

Module Sample test...

Testing suite Basic...
	test addition...
	1 test case: ((1 + 1) == 2) <code style="color:green">✓</code>
	2 test case: This test fails ❌
	Test failed at [example.c:16]

Test pass completed.
Evaluated 1 modules, 1 suites, and 2 tests with 1 failed test case(s).
```

In a larger example, your `test_main()`
would typically call other functions that encapsulate different test modules
and suites that are collections of tests.

```C
#include "test.h"

static void test_foo()
{
    // define a test suite
    SUITE("Foo");

    // display a comment
    COMMENT("testing foo functions...");

    // execute some unit tests
    TEST(TRUE == initFoo());
}

static void test_bar()
{
    // define a test suite
    SUITE("Bar");

    // execute some unit tests
    TEST(barFunction());
}

void test_main(int argc, char *argv[]) {
    // define a module
    MODULE("Foo and Bar testing");

    test_foo();

    test_bar();
}

```

# testy is compatible with CMake/CTest and Github CI

The library `main()` returns 0 on a successful test pass. On a test case failure it
returns the number of failures. These simple steps allow for tests to be run by
the CMake CTest tool and used with Github CI workflows.
