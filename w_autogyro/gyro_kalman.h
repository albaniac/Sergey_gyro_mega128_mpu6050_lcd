// #include "gyro_kalman.h"
#ifndef MY_GYRO_KALMAN_H
#define MY_GYRO_KALMAN_H

#define RESTRICT_PITCH // Comment out to restrict roll to ±90deg instead - please read: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf


class GyroKalman {
public:
	GyroKalman();
	int Init();
	void GetPosition(double &Xx, double &Yy);
	
private:
	Kalman kalmanX; // Create the Kalman instances
	Kalman kalmanY;

	/* IMU Data */
	double accX, accY, accZ;
	double gyroX, gyroY, gyroZ;
	int16_t tempRaw;

	double gyroXangle, gyroYangle; // Angle calculate using the gyro only
	double compAngleX, compAngleY; // Calculated angle using a complementary filter
	double kalAngleX, kalAngleY; // Calculated angle using a Kalman filter

	uint32_t timer;
	uint8_t i2cData[14]; // Buffer for I2C data
};

extern GyroKalman * g_gyro_kalman_p;
#endif
