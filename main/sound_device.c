#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/dac.h>
#include "sound_device.h"

volatile int sample_idx = 0;
esp_timer_handle_t sample_timer;
static const int SAMPLE_INTERVAL_11025 = 91;

void sound_device_set_sample(void *arg)
{
    dac_output_voltage(DAC_CHANNEL_1, sound_device.current_sample->wave_data[sample_idx++]);
    if (sample_idx >= sound_device.current_sample->wave_length)
        sample_idx = 0;
}

void sound_device_play(SoundSampleT *sound_sample)
{
    sound_device.current_sample = sound_sample;
    if (sample_timer && esp_timer_is_active(sample_timer) == 1){
        esp_timer_stop(sample_timer);
    } else {
        const esp_timer_create_args_t timargs = {
            .callback = &sound_device_set_sample,
            .name = "enginesound"};
        esp_timer_create(&timargs, &sample_timer);
    }

    int sample_interval = SAMPLE_INTERVAL_11025 * (1.0 - sound_sample->pitch);
    esp_timer_start_periodic(sample_timer, sample_interval);
}

void sound_device_stop(void) {
    if (sample_timer && esp_timer_is_active(sample_timer) == 1){
        esp_timer_stop(sample_timer);
    }
}

void sound_device_init(void)
{
    esp_err_t err = dac_output_enable(DAC_CHANNEL_1);
    ESP_ERROR_CHECK(err);
    sound_device.play = sound_device_play;
    sound_device.stop = sound_device_stop;
    sound_device.volume = 1;
}

SoundSampleT sound_sample_init(unsigned char *wave_data, unsigned wave_length) {
    SoundSampleT sound;
    sound.volume = 1;
    sound.pitch = 1;
    sound.wave_data = wave_data;
    sound.wave_length = wave_length;

    return sound;
}
