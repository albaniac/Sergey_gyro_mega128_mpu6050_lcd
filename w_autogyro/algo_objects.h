// #include "algo_objects.h"

#ifndef MY_ALGORITHM_AND_PHISICAL_OBJECTS_RU
#define MY_ALGORITHM_AND_PHISICAL_OBJECTS_RU

#include <Arduino.h>

//=======================================================================================
enum HardWare {
	OnlyFirstWeels = 1,
	OnlyLastWeels = 2,
	AllWeels = 3,
	NoCompressor = 4,
	YesCompressor = 5,
	NoName = 6
};
//=======================================================================================
enum CalibratedObjects {
	WeelFirstLeft = 1,
	WeelFirstRight = 2,
	WeelLastLeft = 3,
	WeelLastRight = 4,
	DeviceCompressor = 5,
	NoObjects = 6
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
