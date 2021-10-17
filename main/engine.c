#include "engine.h"


int engine_read_rpm() {
    return engine.rpm;
}

void engine_on_update(int rpm) {
    engine.rpm = rpm;
}