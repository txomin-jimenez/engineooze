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

void test_sound_device_play(SoundSampleT *sound_sample) {
    test_sound_device.volume = 1;
}

void test_sound_device_stop(void) {
    test_sound_device.volume = 0;
}

void test_sound_device_init(void) {
    test_sound_device.play = test_sound_device_play;
    test_sound_device.stop = test_sound_device_stop;
}

unsigned char TEST_SOUND[] = { 0x80, 0x80 };

SoundSampleT a_sound_sample(void) {
    SoundSampleT sound;
    sound.volume = 1;
    sound.pitch = 1;
    sound.wave_data = TEST_SOUND;
    sound.wave_length = 2;

    return sound;
}