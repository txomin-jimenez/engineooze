#define RUN_EXHAUST_TEST(testfunc) \
    UNITY_NEW_TEST(#testfunc) \
    if (TEST_PROTECT()) { \
        exhaust_test_before_each(); \
        testfunc(); \
    } \
    if (TEST_PROTECT() && (!TEST_IS_IGNORED)) \
        exhaust_test_after_each(); \
    UnityConcludeTest();

SoundDevice test_sound_device;

void test_sound_device_play(void) {
    test_sound_device.volume = 100;
}

void test_sound_device_mute(void) {
    test_sound_device.volume = 0;
}

void test_sound_device_init(void)
{
    test_sound_device.play = test_sound_device_play;
    test_sound_device.mute = test_sound_device_mute;
}
