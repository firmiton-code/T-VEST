#ifndef MPU6050_h_
#define MPU6050_h_

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

class GyroClass {
  private:
    Adafruit_MPU6050 mpu;
  public:
    GyroClass();
    bool begin();
    String position();
    float raw_z();
};

extern GyroClass gyro;

#endif // MPU6050_h_