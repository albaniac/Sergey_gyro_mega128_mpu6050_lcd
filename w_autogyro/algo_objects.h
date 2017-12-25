// #include "algo_objects.h"

#ifndef MY_ALGORITHM_AND_PHISICAL_OBJECTS_RU
#define MY_ALGORITHM_AND_PHISICAL_OBJECTS_RU

enum HardWare {
	OnlyFirstWeels,
	OnlyLastWeels,
	AllWeels,
	NoCompressor,
	YesCompressor,
	NoName
};

enum CalibratedObjects {
	WeelFirstLeft,
	WeelFirstRight,
	WeelLastLeft,
	WeelLastRight,
	Compressor,
	NoName
};
#define CALIBRATEDOBJECTSCOUNT 5
#define WEELSMAXCOUNT 4

#endif