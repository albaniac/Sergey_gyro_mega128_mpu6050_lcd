// #include "adc_pressure_metr.h"
#ifndef MY_ADC_PRESSURE_METR_H
#define MY_ADC_PRESSURE_METR_H

#include <Arduino.h>

#define ADC_COUNT 5
#define ADC_MAX 1023
#define ADC_MIN 0

enum ADC_SRC {
  ADC_WEEL_LEFT_FIRST = 0,
  ADC_WEEL_RIGHT_FIRST,
  ADC_WEEL_LEFT_LAST,
  ADC_WEEL_RIGHT_LAST,
  ADC_COMPRESSOR
};

int ADC_PINS [ADC_COUNT] = {
  A0, //ADC_WEEL_LEFT_FIRST
  A1, //ADC_WEEL_RIGHT_FIRST
  A2, //ADC_WEEL_LEFT_LAST
  A3, //ADC_WEEL_RIGHT_LAST
  A4 //ADC_COMPRESSOR   
};

//#define ADC_WEEL_LEFT_FIRST_PIN A0
//#define ADC_WEEL_RIGHT_FIRST_PIN A1
//#define ADC_WEEL_LEFT_LAST_PIN A2
//#define ADC_WEEL_RIGHT_LAST_PIN A3
//#define ADC_COMPRESSOR A4

typedef struct ADC_MAXMIN {
  int max_v;
  int min_v;
  ADC_SRC src;
  int pin_num;
} ADC_MAXMIN_S;

class ADC_Presser {
public:
  ADC_Presser();
  void Init();

private:
 
  ADC_MAXMIN_S adc_maxmin [ADC_COUNT];
};

extern ADC_Presser* g_adc_presser_p;

#endif
