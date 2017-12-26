// #include "algo_objects.h"

#ifndef MY_ALGORITHM_AND_PHISICAL_OBJECTS_RU
#define MY_ALGORITHM_AND_PHISICAL_OBJECTS_RU

#include <Arduino.h>

//=======================================================================================
enum HardWare {
	OnlyFirstWeels,
	OnlyLastWeels,
	AllWeels,
	NoCompressor,
	YesCompressor,
	NoName
};
//=======================================================================================
enum CalibratedObjects {
	WeelFirstLeft,
	WeelFirstRight,
	WeelLastLeft,
	WeelLastRight,
	DeviceCompressor,
	NoObjects
};
#define CALIBRATEDOBJECTSCOUNT 5
#define WEELSMAXCOUNT 4
//=======================================================================================
class Calibration{
public:	
	Calibration(){
		max = 0;
		min = 0;
		delta = (max + min ) / 2;
		was_updated = false;
	};
	
	uint32_t max;
	uint32_t min;
	uint32_t delta;
	bool was_updated;
};
//=======================================================================================
#endif
