#include "mpu6050.h"

GyroClass *gyro_instances;

GyroClass::GyroClass(){
  gyro_instances = this;
}

bool GyroClass::begin(){
  return mpu.begin(0x69);
}

String GyroClass::position()
{
  float position;
  
  // Z axis is gravity measurement value of the sensor
  position = raw_z();
  
  // Standard gravity is 9.8m/s^2
  if(position > 8.0)
    return "Sleep";
  else if((position <= 8.0) && (position > 4.0))
    return "Kifosis Probability";
  else if((position <= 4.0) && (position > -4.0))
    return "Stand";
  else if((position <= -4.0) && (position > -6.0))
    return "Lordosis Probability";
  else
    return "Fall";
}

float GyroClass::raw_z(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  return a.acceleration.z;
}

GyroClass gyro;