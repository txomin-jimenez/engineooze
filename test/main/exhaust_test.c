#include <stdio.h>
#include "unity.h"
#include "exhaust.h"
#include "exhaust_test_helpers.c"

void exhaust_test_before_each(void) {
    sound_device_mute();
}

void exhaust_test_after_each(void) {
}

void test_does_not_emit_sound_when_engine_stopped()
{
    exhaust_init(sound_device_play);

    TEST_ASSERT_EQUAL(0, sound_volume);
}

void test_does_emits_sound_when_engine_is_running()
{
    exhaust_init(sound_device_play);
    int engine_rpm = 1000;

    exhaust_on_update(engine_rpm);

    TEST_ASSERT_NOT_EQUAL(0, sound_volume);
}

int run_exhaust_test()
{
    printf("\nExhaust\n");
    printf("-------\n");
    UnityBegin("Exhaust");
    RUN_EXHAUST_TEST(test_does_not_emit_sound_when_engine_stopped);
    RUN_EXHAUST_TEST(test_does_emits_sound_when_engine_is_running);
    return UNITY_END();
}