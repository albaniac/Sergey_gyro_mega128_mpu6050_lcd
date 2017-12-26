// #include "data_manager.h"
#ifndef MY_DATA_MANAGER_H
#define MY_DATA_MANAGER_H

#include "adc_pressure_metr.h"
#include "algo_objects.h"
#include <Arduino.h>

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

	uint8_t SetCalibrationMaxByName(CalibratedObjects name, uint32_t max);
	uint8_t SetCalibrationMinByName(CalibratedObjects name, uint32_t min);

private:
	HardWare weels_t_;
	HardWare compressor_t_;
	Weel weels_[WEELSMAXCOUNT]; // 
	Compressor compressor_;
};
//=======================================================================================
extern DataManager* g_data_manager_p;
#endif
