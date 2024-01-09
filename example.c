#include <stdio.h>
#include "test.h"

int test_main(int argc, char *argv[]) {
    // define a module
    MODULE("Sample test");

    // define a test suite
    SUITE("Basic");

    // display a comment
    COMMENT("test addition...");

    // execute a unit test
    TEST(((1 + 1) == 2));

    return 0;
}