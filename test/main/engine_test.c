#include <stdio.h>
#include "unity.h"
#include "engine.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_can_be_started()
{
    int result = engine_start();
    TEST_ASSERT_EQUAL(1, result);
}

void run_engine_test() {
    printf("Engine\n");

    RUN_TEST(test_can_be_started);
}