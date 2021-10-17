#define RUN_EXHAUST_TEST(testfunc) \
    UNITY_NEW_TEST(#testfunc) \
    if (TEST_PROTECT()) { \
        exhaust_test_before_each(); \
        testfunc(); \
    } \
    if (TEST_PROTECT() && (!TEST_IS_IGNORED)) \
        exhaust_test_after_each(); \
    UnityConcludeTest();

int sound_volume;

void sound_device_play() {
    sound_volume = 100;
}

void sound_device_mute() {
    sound_volume = 0;
}