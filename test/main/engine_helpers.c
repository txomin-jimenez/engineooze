void stub_engine_stopped() {
    engine.rpm = 0;
}

void stub_engine_rpm(int rpm) {
    engine_on_update(rpm);
}