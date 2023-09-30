/*
* PT2258 WITH POTENTIOMETER EXAMPLE
* potentiometer-A0 connect
* 2023-09-30
*/

#include <PT2258.h>
#include <Wire.h>

byte v = 0;
byte buf=0;

PT2258 pt(1,0); // 1,0 ==> code0=1 , code1=0 adress is 0x44

void setup() {

  Serial.begin(9600);
  //Wire.begin(); cpp contains.

  pinMode(A0,INPUT);

  if(!pt.pt_begin())Serial.println("PT2258 connecting is success");
  else Serial.println("NO MATCHED ADRESS. /n check PT2258 adress."); 
}


void loop() {
  v = map(analogRead(A0),0,1023,0,100);

  if(buf!=v){
    pt.setvolume_per(v,0); //ALL channel control
    buf = v;
  }

  delay(50);
}
