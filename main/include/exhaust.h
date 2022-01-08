#ifndef EXHAUST_H_
#define EXHAUST_H_

#include "sound_device.h"
struct Exhaust {
  SoundDevice sound_device;
  int idle_rpm;
  SoundSampleT *idle_sound;
} exhaust;

void exhaust_init(SoundDevice sound_device, int idle_rpm, SoundSampleT *idle_sound);
void exhaust_on_update(int rpm);

#endif // EXHAUST_H_