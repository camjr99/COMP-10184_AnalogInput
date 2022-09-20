//I, Cameron Randall, 000820614 guanantee that this is my work and my work only.

#include <Arduino.h>

  double convert(int x, int in_min, int in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }

void setup() {
  Serial.begin(115200); 
}

void loop() {
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
 
  // print value to the USB port 
  // can't seem to get a value of 0 - my range is 9 or 10 to 1024
  double mVal = convert(iVal, 9, 1024, 0, 50);
  String output;
  if (mVal < 10) {
    output = "Cold!";
  } else if ((mVal >= 10) && (mVal < 15)) {
    output = "Cool";
  } else if ((mVal >= 15) && (mVal < 25)) {
    output = "Perfect";
  } else if ((mVal >= 25) && (mVal < 30)) {
    output = "Warm";
  } else if ((mVal >= 30) && (mVal <= 35)) {
    output = "Hot";
  } else if (mVal > 35) {
    output = "Too Hot!";
  }
  Serial.printf("Digitized output of %u is equivalent to a temperature input of %4.2f deg. C, which is %s \n", iVal, mVal, output);
 
  delay(2000); 
}