// #include "data_manager.h"
#ifndef MY_DATA_MANAGER_H
#define MY_DATA_MANAGER_H

#include "adc_pressure_metr.h"
#include "algo_objects.h"
#include <Arduino.h>

//=======================================================================================
class Calibration{
public:	
	Calibration(){
		max = ADC_MAX;
		min = ADC_MIN;
		delta = (ADC_MAX + ADC_MIN ) / 2;
		was_updated = false;
	};
	
	uint32_t max;
	uint32_t min;
	uint32_t delta;
	bool was_updated;
};
//=======================================================================================
class Weel{
public:
  Weel(){
    name_ = NoObjects;
  }
	CalibratedObjects name_;
	Calibration calibration_;
	ADCHolder adc_holder_;
};
//=======================================================================================
class Compressor{
public:
  Compressor(){
    name_ = NoObjects;
  }
	CalibratedObjects name_;
	Calibration calibration_;
	ADCHolder adc_holder_;	
};
//=======================================================================================
class DataManager {
public:
	DataManager();
	uint8_t Init();
	
private:
	HardWare weels_t_;
	HardWare compressor_t_;
	Weel weels_[WEELSMAXCOUNT]; // 
	Compressor compressor_;
};
//=======================================================================================
extern DataManager* g_data_manager_p;
#endif
