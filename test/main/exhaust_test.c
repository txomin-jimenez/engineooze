#include <stdio.h>
#include "unity.h"
#include "exhaust.h"
#include "exhaust_test_helpers.c"

void exhaust_test_before_all(void) {
    test_sound_device_init();
}

void exhaust_test_before_each(void) {
    test_sound_device.mute();
}

void exhaust_test_after_each(void) {
}

void test_does_not_emit_sound_when_engine_stopped()
{
    exhaust_init(test_sound_device);
    int engine_rpm = 1000;
    exhaust_on_update(engine_rpm);
    engine_rpm = 0;
    
    exhaust_on_update(engine_rpm);

    TEST_ASSERT_EQUAL(0, test_sound_device.volume);
}

void test_does_emits_sound_when_engine_is_running()
{
    exhaust_init(test_sound_device);
    int engine_rpm = 1000;

    exhaust_on_update(engine_rpm);

    TEST_ASSERT_NOT_EQUAL(0, test_sound_device.volume);
}

int run_exhaust_test()
{
    printf("\nExhaust\n");
    printf("-------\n");
    UnityBegin("Exhaust");
    exhaust_test_before_all();
    RUN_EXHAUST_TEST(test_does_not_emit_sound_when_engine_stopped);
    RUN_EXHAUST_TEST(test_does_emits_sound_when_engine_is_running);
    return UNITY_END();
}