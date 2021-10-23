#define RUN_ENGINE_TEST(testfunc) \
    UNITY_NEW_TEST(#testfunc) \
    if (TEST_PROTECT()) { \
        engine_test_before_each(); \
        testfunc(); \
    } \
    if (TEST_PROTECT() && (!TEST_IS_IGNORED)) \
        engine_test_after_each(); \
    UnityConcludeTest();

void stub_engine_stopped() {
    engine_on_update(0);
}

void stub_engine_rpm(int rpm) {
    engine_on_update(rpm);
}