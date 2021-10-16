#include <stdio.h>
#include "unity.h"
#include "engine_test.h"


int main(int argc, char **argv)
{
    printf("Running tests...\n\n");
    UNITY_BEGIN();

    run_engine_test();

    int failures = UNITY_END();
    return failures;
}