#include "exhaust.h"

void exhaust_init(void (*sound_device_play)(void)) {
    exhaust.sound_device_play = sound_device_play;
}

void exhaust_on_update(int rpm) {
    if (rpm > 0) {
        exhaust.sound_device_play();
    }
}