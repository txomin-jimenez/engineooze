#include <stdio.h>
#include "unity.h"
#include "engine_test.c"
#include "exhaust_test.c"


int main(int argc, char **argv)
{
    printf("\nRunning tests...\n");
    int failures = 0;

    failures += run_engine_test();
    failures += run_exhaust_test();

    return failures;
}