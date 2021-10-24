#include <stdio.h>
#include "exhaust.h"

float _calc_pitch_from(int rpm) {
    return (rpm - exhaust.idle_rpm) / (float)exhaust.idle_rpm;
}

void exhaust_init(SoundDevice sound_device, int idle_rpm) {
    exhaust.sound_device = sound_device;
    exhaust.idle_rpm = idle_rpm;
}

void exhaust_on_update(int rpm) {
    if (rpm > 0) {
        float pitch = _calc_pitch_from(rpm);
        exhaust.sound_device.play(pitch);
    } else {
        exhaust.sound_device.mute();
    }
}