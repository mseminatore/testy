#include <stdio.h>
#include "test.h"

int test_main(int argc, char *argv[]) {
    MODULE("Sample test");

    SUITE("Basic");

    TEST(((1 + 1) == 2));

    return 0;
}