// #include "adc_pressure_metr.h"
#ifndef MY_ADC_PRESSURE_METR_H
#define MY_ADC_PRESSURE_METR_H

#include <Arduino.h>
#include "algo_objects.h"

#define ADC_MAX 1023
#define ADC_MIN 0

#define ADC_WEEL_FIRST_LEFT_PIN A0
#define ADC_WEEL_FIRST_RIGHT_PIN A1
#define ADC_WEEL_LAST_LEFT_PIN A2
#define ADC_WEEL_LAST_RIGHT_PIN A3
#define ADC_COMPRESSOR A4

class ADCHolder {
public:
  ADCHolder(){
	pin_num = -1;	
  }
  int pin_num;
  uint32_t GetRaw();
};

#endif
