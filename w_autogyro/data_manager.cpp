#include "data_manager.h"
#include "eeprom_worker.h"
#include "adc_pressure_metr.h"
#include "gyro_kalman.h"
//===============================================================================
static DataManager g_data_manager;
DataManager* g_data_manager_p = &g_data_manager;
//===============================================================================
DataManager::DataManager(){
	compressor_t_ = NoName;
	weels_t_ = NoName;
};
//===============================================================================
uint8_t DataManager::Init(){
	compressor_t_ = g_eeprom_p->ReadCompressorT();
	weels_t_ = g_eeprom_p->ReadWeelsT();

	if (compressor_t_ = NoName){
		// TODO inform Error
	};
	
	if (compressor_t_ == YesCompressor){
		compressor_.name_ = DeviceCompressor;
		compressor_.adc_holder_.pin_num = ADC_COMPRESSOR;
		g_eeprom_p->GetFromMemoryCalibrationByName(	compressor_.name_, compressor_.calibration_);
	};
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	if (weels_t_ = NoName){
		// TODO inform Error
	};

	if (weels_t_ == OnlyFirstWeels || weels_t_ == AllWeels){
		weels_[0].name_ = WeelFirstLeft;
		weels_[0].adc_holder_.pin_num = ADC_WEEL_FIRST_LEFT_PIN;
		g_eeprom_p->GetFromMemoryCalibrationByName(	weels_[0].name_, weels_[0].calibration_);
											
		weels_[1].name_ = WeelFirstRight;
		weels_[1].adc_holder_.pin_num = ADC_WEEL_FIRST_RIGHT_PIN;
		g_eeprom_p->GetFromMemoryCalibrationByName(	weels_[1].name_, weels_[1].calibration_);
	}
	
	if (weels_t_ == OnlyLastWeels || weels_t_ == AllWeels){
		weels_[2].name_ = WeelLastLeft;
		weels_[2].adc_holder_.pin_num = ADC_WEEL_LAST_LEFT_PIN;
		g_eeprom_p->GetFromMemoryCalibrationByName(	weels_[2].name_, weels_[2].calibration_);
											
		weels_[3].name_ = WeelLastRight;
		weels_[3].adc_holder_.pin_num = ADC_WEEL_LAST_RIGHT_PIN;
		g_eeprom_p->GetFromMemoryCalibrationByName(	weels_[3].name_, weels_[3].calibration_);
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	g_eeprom_p->GetFromMemoryGyroZerroCalibration(gyroscope_.x_zerro_, gyroscope_.y_zerro_);

	return 0;
};
//===============================================================================
uint8_t DataManager::SetCalibrationMaxByName(CalibratedObjects name){
	if (compressor_.name_ == name){
		compressor_.calibration_.max = compressor_.adc_holder_.GetRaw();
		g_eeprom_p->SetInMemoryCalibrationByName(compressor_.name_, compressor_.calibration_);
		return 0;
	}else{ // weels
		for (uint8_t i = 0; i < WEELSMAXCOUNT; i++){
			if (weels_[i].name_ == name){
				weels_[i].calibration_.max = weels_[i].adc_holder_.GetRaw();
				g_eeprom_p->SetInMemoryCalibrationByName(weels_[i].name_, weels_[i].calibration_);
				return 0;
			}
		}
		
		// if we are here, there is no such name
		// TODO Error
		return 1;
	}
};
//===============================================================================
uint8_t DataManager::SetCalibrationMinByName(CalibratedObjects name){
	if (compressor_.name_ == name){
		compressor_.calibration_.min = compressor_.adc_holder_.GetRaw();
		g_eeprom_p->SetInMemoryCalibrationByName(compressor_.name_, compressor_.calibration_);
		return 0;
	}else{ // weels
		for (uint8_t i = 0; i < WEELSMAXCOUNT; i++){
			if (weels_[i].name_ == name){
				weels_[i].calibration_.min = weels_[i].adc_holder_.GetRaw();
				g_eeprom_p->SetInMemoryCalibrationByName(weels_[i].name_, weels_[i].calibration_);
				return 0;
			}
		}
		
		// if we are here, there is no such name
		// TODO Error
		return 1;
	}
};
//===============================================================================
uint8_t DataManager::SetCalibrationGyroZerro(){
	g_gyro_kalman_p->GetPosition(gyroscope_.x_zerro_, gyroscope_.y_zerro_);
	g_eeprom_p->SetInMemoryGyroZerroCalibration(gyroscope_.x_zerro_, gyroscope_.y_zerro_);
	return 0;
};
//===============================================================================
uint8_t DataManager::SetHardWare(HardWare hard_ware){
	if (hard_ware == YesCompressor || hard_ware == NoCompressor){
		compressor_t_ = hard_ware;
	}else{
		weels_t_ = hard_ware;
	}
};
//===============================================================================
