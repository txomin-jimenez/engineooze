#include <stdio.h>
#include "exhaust.h"

float _calc_volume_from(int rpm) {
  if (rpm > 0) {
    return 1;
  } else {
    return 0;
  }
}

float _calc_pitch_from(int rpm) {
    return (rpm - exhaust.idle_rpm) / (float)exhaust.idle_rpm;
}

void exhaust_init(SoundDevice sound_device, int idle_rpm, SoundSampleT *idle_sound) {
    exhaust.sound_device = sound_device;
    exhaust.idle_rpm = idle_rpm;
    exhaust.idle_sound = idle_sound;
}

void exhaust_on_update(int rpm) {
    exhaust.idle_sound->volume = _calc_volume_from(rpm);
    exhaust.idle_sound->pitch = _calc_pitch_from(rpm);
    if (rpm > 0) {
        exhaust.sound_device.play(exhaust.idle_sound);
    } else {
        exhaust.sound_device.stop();
    }
}