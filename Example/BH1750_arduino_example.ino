/*GY-30 light sensitivity sensor example*/
#include "bh1750fvi.h"

void setup() {
  Serial.begin(115200);
  while (!Serial);

  lightSensor_begin(ADDRESS1, ONE_TIME_AUTO);       //initializing GY-30 or BH1750FVI breakout board, with ADDRESS1 and in ONE_TIME_AUTO mode
}

void loop() {
  Serial.println(lightSensor_meter(), DEC);     
  delay(500);
}
