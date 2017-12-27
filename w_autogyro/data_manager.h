// #include "data_manager.h"
#ifndef MY_DATA_MANAGER_H
#define MY_DATA_MANAGER_H

#include "adc_pressure_metr.h"
#include "pressurer.h"
#include "algo_objects.h"
#include <Arduino.h>

//=======================================================================================
class Weel{
public:
  Weel()
  : name_(NoObjects)
  {
  }
	CalibratedObjects name_;
	Calibration calibration_;
	ADCHolder adc_holder_;
	Pressurer pressurer_;
};
//=======================================================================================
class Compressor{
public:
  Compressor()
  : name_(NoObjects)
  {
  }
	CalibratedObjects name_;
	Calibration calibration_;
	ADCHolder adc_holder_;	
};
//=======================================================================================
class GyroScopeDevice{
public:
  GyroScopeDevice()
  : name_(CaliObbjGyroScope),
  x_max_(0),
  x_min_(0),
  x_zerro_(0),
  y_max_(0),
  y_min_(0),
  y_zerro_(0) 
  {
  }
  
	CalibratedObjects name_;
	double x_max_;
	double x_min_;
	double x_zerro_;
	double y_max_;
	double y_min_;
	double y_zerro_;
	
};
//=======================================================================================
class DataManager {
public:
	DataManager();
	uint8_t Init();

	uint8_t SetCalibrationMaxByName(CalibratedObjects name);
	uint8_t SetCalibrationMinByName(CalibratedObjects name);
	uint8_t SetCalibrationGyroZerro();
	uint8_t SetHardWare(HardWare hard_ware);

private:
	HardWare weels_t_;
	HardWare compressor_t_;
	Weel weels_[WEELSMAXCOUNT]; // 
	Compressor compressor_;
	GyroScopeDevice gyroscope_;
};
//=======================================================================================
extern DataManager* g_data_manager_p;
#endif
