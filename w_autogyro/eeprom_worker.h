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
	uint8_t GetCalibrationByName(CalibratedObjects name, uint32_t& min, uint32_t& max, uint32_t& delta );
	
private:
	
};

extern EEPROMWorker* g_eeprom_p;
#endif
