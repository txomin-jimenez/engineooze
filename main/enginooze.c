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
    exhaust_init(sound_device);
    
    engine_on_update(1000);
    int engine_rpm = engine_read_rpm();
    exhaust_on_update(engine_rpm);
    
    while (1)
    {
        vTaskDelay(100000 / portTICK_PERIOD_MS);
    };
    ESP_LOGI(TAG, "Finished!");
}
