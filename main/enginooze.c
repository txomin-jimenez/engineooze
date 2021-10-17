#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/dac.h>
#include "sounds/idle.h"
#include "engine.h"

static const char *TAG = "Enginooze";
volatile int sample_idx = 0;
static const int SAMPLE_INTERVAL_11025 = 90;

void enable_sound(void)
{
    esp_err_t err = dac_output_enable(DAC_CHANNEL_1);
    ESP_ERROR_CHECK(err);
}

void set_sample(void *arg)
{
    dac_output_voltage(DAC_CHANNEL_1, sound_idle[sample_idx++]);
    if (sample_idx >= sound_idle_len)
        sample_idx = 0;
}

void idle(void)
{
    const esp_timer_create_args_t timargs = {
        .callback = &set_sample,
        .name = "enginesound"};
    esp_timer_handle_t every;
    esp_timer_create(&timargs, &every);
    esp_timer_start_periodic(every, SAMPLE_INTERVAL_11025);
}

void app_main(void)
{
    ESP_LOGI(TAG, "Started!");
    enable_sound();
    int engine_rpm = engine_read_rpm();
    ESP_LOGI(TAG, "Engine RPM: %i", engine_rpm);

    idle();
    
    while (1)
    {
        vTaskDelay(100000 / portTICK_PERIOD_MS);
    };
    ESP_LOGI(TAG, "Finished!");
}
