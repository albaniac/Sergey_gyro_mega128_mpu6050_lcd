#include "adc_pressure_metr.h"

uint32_t ADCHolder::GetRaw(){
	if (pin_num < 0){
		return ADC_MAX+1;
	}
	else{
		return analogRead(pin_num);
	}
;
