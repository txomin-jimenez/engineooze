#ifndef SOUND_DEVICE_H_
#define SOUND_DEVICE_H_

typedef struct SoundSampleT {
    float volume;
    float pitch;
    unsigned char *wave_data;
    unsigned int wave_length;
} SoundSampleT;

typedef struct SoundDeviceT {
    float volume;
    SoundSampleT *current_sample;
    void (*play)(SoundSampleT *sound_sample);
    void (*stop)(void);
} SoundDevice;

SoundDevice sound_device;

void sound_device_init(void);
SoundSampleT sound_sample_init(unsigned char *wave_data, unsigned int wave_length);

#endif // SOUND_DEVICE_H_