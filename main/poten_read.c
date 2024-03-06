#include <stdio.h>
#include <stdlib.h>

#include "driver/adc.h"
#include "driver/adc_types_legacy.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"

esp_adc_cal_characteristics_t adc2_chars;
int adc_value;

void app_main(void) {
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_12, ADC_WIDTH_BIT_DEFAULT,
                           0, &adc2_chars);
  adc2_config_channel_atten(ADC2_CHANNEL_3, ADC_ATTEN_DB_12);

  while (1) {
    adc2_get_raw(ADC2_CHANNEL_3, ADC_WIDTH_BIT_DEFAULT, &adc_value);
    printf("ADC Value: %d", adc_value);
    printf("\n");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
