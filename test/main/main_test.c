#include <stdio.h>
#include "unity.h"
#include "engine_test.c"


int main(int argc, char **argv)
{
    printf("\nRunning tests...\n\n");
    int failures;

    failures = run_engine_test();

    return failures;
}