#include <stdio.h>
#include "unity.h"
#include "engine.h"
#include "engine_helpers.c";

void setUp(void) {
    stub_engine_stopped();
}

void tearDown(void) {
    // clean stuff up here
}

void test_provides_rpm_when_stopped()
{
    stub_engine_stopped();

    int result = engine_read_rpm();

    TEST_ASSERT_EQUAL(0, result);
}

void test_provides_rpm_when_running()
{
    stub_engine_rpm(3210);

    int result = engine_read_rpm();

    TEST_ASSERT_EQUAL(3210, result);
}

void run_engine_test() {
    printf("Engine\n");

    RUN_TEST(test_provides_rpm_when_stopped);
    RUN_TEST(test_provides_rpm_when_running);
}