#include "data_manager.h"
#include "eeprom_worker.h"
#include "adc_pressure_metr.h"


static DataManager g_data_manager;
DataManager* g_data_manager_p = &g_data_manager;


DataManager::DataManager(){
	compressor_t_ = NoName;
	weels_t_ = NoName;
};

	Weel weels_[CALIBRATEDOBJECTSCOUNT];
	Compressor compressor_;

DataManager::Init(){
	compressor_t_ = g_eeprom_p->ReadCompressorT();
	weels_t_ = g_eeprom_p->ReadWeelsT();

	if (compressor_t_ = NoName){
		// TODO inform Error
	};
	
	if (compressor_t_ == YesCompressor){
		compressor_.name = Compressor;
		compressor_.adc_holder_.pin_num = ADC_COMPRESSOR;
		g_eeprom_p->GetCalibrationByName(	compressor_.name, 
											compressor_.min, 
											compressor_.max, 
											compressor_.delta );
	};
	
	if (weels_t_ = NoName){
		// TODO inform Error
	};

	if (weels_t_ = OnlyFirstWeels || weels_t_ = AllWeels){
		weels_[0].name_ = WeelFirstLeft;
		weels_[0].adc_holder_.pin_num = ADC_WEEL_FIRST_LEFT_PIN;
		g_eeprom_p->GetCalibrationByName(	weels_[0].name, 
											weels_[0].min, 
											weels_[0].max, 
											weels_[0].delta );
											
		weels_[1].name_ = WeelFirstRight;
		weels_[1].adc_holder_.pin_num = ADC_WEEL_FIRST_RIGHT_PIN;
		g_eeprom_p->GetCalibrationByName(	weels_[1].name, 
											weels_[1].min, 
											weels_[1].max, 
											weels_[1].delta );
	}
	
	if (weels_t_ = OnlyLastWeels || weels_t_ = AllWeels){
		weels_[2].name_ = WeelLastLeft;
		weels_[2].adc_holder_.pin_num = ADC_WEEL_LAST_LEFT_PIN;
		g_eeprom_p->GetCalibrationByName(	weels_[2].name, 
											weels_[2].min, 
											weels_[2].max, 
											weels_[2].delta );
											
		weels_[3].name_ = WeelLastRight;
		weels_[3].adc_holder_.pin_num = ADC_WEEL_LAST_RIGHT_PIN;
		g_eeprom_p->GetCalibrationByName(	weels_[3].name, 
											weels_[3].min, 
											weels_[3].max, 
											weels_[3].delta );
	}
};




