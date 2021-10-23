#ifndef SOUND_DEVICE_H_
#define SOUND_DEVICE_H_

typedef struct SoundDeviceT {
    int volume;
    void (*play)(void);
    void (*mute)(void);
} SoundDevice;

SoundDevice sound_device;

void sound_device_init(void);

#endif // SOUND_DEVICE_H_