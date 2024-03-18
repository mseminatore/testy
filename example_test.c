#include <stdio.h>
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
    TESTEX("This test passes", (1==1));
}