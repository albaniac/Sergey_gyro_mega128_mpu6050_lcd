// #include "eeprom_worker.h"
#ifndef MY_EEPROM_WORKER_H
#define MY_EEPROM_WORKER_H

#include "algo_objects.h"
#include <Arduino.h>

class EEPROMWorker{
public:
	EEPROMWorker();

	HardWare ReadCompressorT();
	void WriteCompressorT(HardWare hardware);

	HardWare ReadWeelsT();
	void WriteWeelsT(HardWare hardware);

	uint8_t GetFromMemoryCalibrationByName(CalibratedObjects name, Calibration& calibration );
	uint8_t SetInMemoryCalibrationByName(CalibratedObjects name, Calibration calibration);

	uint8_t GetFromMemoryGyroZerroCalibration(double& x, double& y);
	uint8_t SetInMemoryGyroZerroCalibration(double x, double y);
	
private:
	
};

extern EEPROMWorker* g_eeprom_p;
#endif
