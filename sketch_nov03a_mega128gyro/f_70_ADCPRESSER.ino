// This means that it will map input voltages between 0 and 5 volts into integer values between 0 and 1023. 
// This yields a resolution between readings of: 5 volts / 1024

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

class ADC_PRESSER {
  
  ADC_MAXMIN_S adc_maxmin [ADC_COUNT];
    
  ADC_PRESSER();
  
  void adc_init(){
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


};



