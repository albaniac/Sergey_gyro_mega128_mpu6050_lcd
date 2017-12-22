#include "adc_pressure_metr.h"

ADC_Presser g_adc_presser;
ADC_Presser* g_adc_presser_p = &g_adc_presser;

ADC_Presser::ADC_Presser(){
	
}

void ADC_Presser::Init(){
  for (unsigned char i = 0; i < ADC_COUNT; i++){
    adc_maxmin[i].max_v = ADC_MAX;
    adc_maxmin[i].min_v = ADC_MIN;
    adc_maxmin[i].pin_num = ADC_PINS[i];
  }
  adc_maxmin[0].src = ADC_WEEL_LEFT_FIRST;
  adc_maxmin[1].src = ADC_WEEL_RIGHT_FIRST;
  adc_maxmin[2].src = ADC_WEEL_LEFT_LAST;
  adc_maxmin[3].src = ADC_WEEL_RIGHT_LAST;
  adc_maxmin[4].src = ADC_COMPRESSOR;
}
