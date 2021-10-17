#include <stdio.h>
#include "unity.h"
#include "engine.h"
#include "engine_test_helpers.c"

void engine_test_before_each(void) {
    stub_engine_stopped();
}

void engine_test_after_each(void) {
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

int run_engine_test()
{
    printf("Engine\n");
    printf("------\n");
    UnityBegin("Engine");
    RUN_ENGINE_TEST(test_provides_rpm_when_stopped);
    RUN_ENGINE_TEST(test_provides_rpm_when_running);
    return UNITY_END();
}