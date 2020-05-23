#include <Wire.h>
#include "SparkFun_Qwiic_Scale_NAU7802_Arduino_Library.h"

NAU7802 myScale; //Create instance of the NAU7802 class

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (myScale.begin() == false)
  {
    Serial.println("Scale not detected. Please check wiring. Freezing...");
    while (1);
  }
}

void loop() {
  if(myScale.available() == true)
  {
    long currentReading = myScale.getReading();
    String L_reading = String(currentReading);
    Serial.println('L' + L_reading);
  }
  int flexors = analogRead(A0);
  int extensors = analogRead(A1);
  // print out the value you read:
  Serial.println('F' + String(flexors));
  Serial.println('E' + String(extensors));
  delay(10);        // delay in between reads for stability
}
