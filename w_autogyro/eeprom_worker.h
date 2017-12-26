// #include "eeprom_worker.h"
#ifndef MY_EEPROM_WORKER_H
#define MY_EEPROM_WORKER_H

#include "algo_objects.h"
#include <Arduino.h>

class EEPROMWorker{
public:
	EEPROMWorker();
	HardWare ReadCompressorT();
	HardWare ReadWeelsT();
	uint8_t GetCalibrationByName(CalibratedObjects name, Calibration& calibration );
	uint8_t SetCalibrationByName(CalibratedObjects name, Calibration calibration);
	
private:
	
};

extern EEPROMWorker* g_eeprom_p;
#endif
