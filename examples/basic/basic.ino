/*
* PT2258 BASIC
* setvoulume range 0-79 /// setvoulume_per range 0-100
* 2023-09-30
*/

#include <PT2258.h>
#include <Wire.h>

PT2258 pt(1,0); // 1,0 ==> code0=1 , code1=0 adress is 0x44

void setup() {

  Serial.begin(9600);
  //Wire.begin(); cpp contains.

  if(!pt.pt_begin())Serial.println("PT2258 connecting is success");
  else Serial.println("NO MATCHED ADRESS. /n check PT2258 adress."); 
}


void loop() {
  pt.setvolume(79,0); //all channel volume max
  delay(5000);

  pt.mute(1,0); //all channel mute on
  delay(5000);

  pt.mute(0,0); //all channel mute off
  delay(5000);

  pt.setvolume(0,1); //channel 1 voulume 0
  delay(5000);

  pt.setvolume(0,2); //channel 2 voulume 0
  delay(5000);

  pt.setvolume(79,0); //all channel volume max
  delay(5000);

  pt.setvolume_per(0,1); //channel 1 voulume 0
  delay(5000);

  pt.setvolume_per(100,1); //channel 1 voulume 100
  delay(5000);
}
