#include <Arduino.h>
#include "sensor/mpu6050.h"
#include "device_config.h"
#include "network/network.h"

String lastPosition;

void mpu_task(void *param){
  while(1){
    if(gyro.position() != lastPosition){
      lastPosition = gyro.position();
      Serial.print("New Position : ");
      Serial.println(lastPosition);
    }
    
    Serial.print("Z axis : ");
    Serial.println(gyro.raw_z());

    vTaskDelay(1000);
  }
}

void setup() {
  Serial.begin(115200);
  net.begin();
  pinMode(23, OUTPUT);
  if(gyro.begin()){
    Serial.println("Sensor Detected");
  } else{
    Serial.println("Sensor Not Detected");
  }

  xTaskCreate(mpu_task, "MPU Task", 5000, NULL, 3, NULL);
}

void loop() {
  digitalWrite(23, HIGH);
  delay(500);
  digitalWrite(23, LOW);
  delay(500);
}