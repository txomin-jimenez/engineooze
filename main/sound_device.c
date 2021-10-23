#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/dac.h>
#include "sounds/idle.h"
#include "sound_device.h"

volatile int sample_idx = 0;
static const int SAMPLE_INTERVAL_11025 = 90;

void sound_device_set_sample(void *arg)
{
    dac_output_voltage(DAC_CHANNEL_1, sound_idle[sample_idx++]);
    if (sample_idx >= sound_idle_len)
        sample_idx = 0;
}

void sound_device_play(void)
{
    const esp_timer_create_args_t timargs = {
        .callback = &sound_device_set_sample,
        .name = "enginesound"};
    esp_timer_handle_t every;
    esp_timer_create(&timargs, &every);
    esp_timer_start_periodic(every, SAMPLE_INTERVAL_11025);
}

void sound_device_mute(void) {}

void sound_device_init(void)
{
    esp_err_t err = dac_output_enable(DAC_CHANNEL_1);
    ESP_ERROR_CHECK(err);
    sound_device.play = sound_device_play;
    sound_device.mute = sound_device_mute;
}
