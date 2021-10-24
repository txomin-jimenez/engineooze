#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/dac.h>
#include "sounds/idle.h"
#include "sound_device.h"

volatile int sample_idx = 0;
esp_timer_handle_t sample_timer;
static const int SAMPLE_INTERVAL_11025 = 91;

void sound_device_set_sample(void *arg)
{
    dac_output_voltage(DAC_CHANNEL_1, sound_idle[sample_idx++]);
    if (sample_idx >= sound_idle_len)
        sample_idx = 0;
}

void sound_device_play(float pitch)
{
    if (sample_timer && esp_timer_is_active(sample_timer) == 1){
        esp_timer_stop(sample_timer);
    } else {
        const esp_timer_create_args_t timargs = {
            .callback = &sound_device_set_sample,
            .name = "enginesound"};
        esp_timer_create(&timargs, &sample_timer);
    }
    
    int sample_interval = SAMPLE_INTERVAL_11025 * (1.0 - pitch);
    esp_timer_start_periodic(sample_timer, sample_interval);
}

void sound_device_mute(void) {}

void sound_device_init(void)
{
    esp_err_t err = dac_output_enable(DAC_CHANNEL_1);
    ESP_ERROR_CHECK(err);
    sound_device.play = sound_device_play;
    sound_device.mute = sound_device_mute;
}
