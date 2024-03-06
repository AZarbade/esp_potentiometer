#include <stdio.h>
#include <stdlib.h>

#include "driver/adc.h"
#include "driver/adc_types_legacy.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "portmacro.h"

esp_adc_cal_characteristics_t adc2_chars;

void app_main(void) {
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_12, ADC_WIDTH_BIT_DEFAULT,
                           0, &adc2_chars);
  adc2_config_channel_atten(ADC2_CHANNEL_3, ADC_ATTEN_DB_12);

  while (1) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
      int adc_value;
      adc2_get_raw(ADC2_CHANNEL_3, ADC_WIDTH_BIT_DEFAULT, &adc_value);
      sum += adc_value;
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    int avg_adc_value = sum / 10;
    // printf("Average ADC Value: %d\n", avg_adc_value);
    printf("%d\n", avg_adc_value);
  }
}
