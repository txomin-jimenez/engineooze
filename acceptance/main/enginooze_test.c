#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "engine.h"
#include "exhaust.h"
#include "sound_device.h"
#include "sounds/idle.h"

static const char *TAG = "Acceptance";

void app_main(void)
{
    ESP_LOGI(TAG, "Running tests...");

    sound_device_init();

    SoundSampleT idle_sound = sound_sample_init(wave_idle_data, wave_idle_len);
    exhaust_init(sound_device, IDLE_RPM, &idle_sound);
    engine_on_update(IDLE_RPM);

    int engine_rpm = engine_read_rpm();
    exhaust_on_update(engine_rpm);

    int times = 3;
    while (times > 0)
    {
        times = times - 1;
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        while(engine_rpm < 1500) {
            engine_rpm+=50;
            exhaust_on_update(engine_rpm);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        while(engine_rpm > IDLE_RPM) {
            engine_rpm-=50;
            exhaust_on_update(engine_rpm);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    };
    while(engine_rpm > 0) {
        engine_rpm-=50;
        exhaust_on_update(engine_rpm);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    ESP_LOGI(TAG, "Finished!");
}