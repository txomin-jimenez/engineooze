#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "engine.h"
#include "exhaust.h"
#include "sound_device.h"

static const char *TAG = "Enginooze";

void app_main(void)
{
    ESP_LOGI(TAG, "Started!");
    sound_device_init();
    int idle_rpm = 1000;
    exhaust_init(sound_device, idle_rpm);
    
    engine_on_update(idle_rpm);
    int engine_rpm = engine_read_rpm();
    exhaust_on_update(engine_rpm);
    
    while (1)
    {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        while(engine_rpm < 1450) {
            engine_rpm+=10;
            exhaust_on_update(engine_rpm);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
        vTaskDelay(3000 / portTICK_PERIOD_MS);
        while(engine_rpm > 1000) {
            engine_rpm-=10;
            exhaust_on_update(engine_rpm);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }     
        vTaskDelay(5000 / portTICK_PERIOD_MS);   
    };
    ESP_LOGI(TAG, "Finished!");
}
