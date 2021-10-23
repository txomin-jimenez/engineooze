#include "exhaust.h"

void exhaust_init(SoundDevice sound_device) {
    exhaust.sound_device = sound_device;
}

void exhaust_on_update(int rpm) {
    if (rpm > 0) {
        exhaust.sound_device.play();
    } else {
        exhaust.sound_device.mute();
    }
}