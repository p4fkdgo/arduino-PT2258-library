#include <Arduino.h>
#include <Wire.h>
#include "PT2258.h"

PT2258::PT2258(boolean a, boolean b){
  if(a==1&b==1) _adr = 0x46; //code 0 == 1 //code 1 == 1
  if(a==1&b==0) _adr = 0x44; //code 0 == 1 //code 1 == 0
  if(a==0&b==1) _adr = 0x42; //code 0 == 0 //code 1 == 1
  if(a==0&b==0) _adr = 0x40; //code 0 == 0 //code 1 == 0
}

byte PT2258::pt_begin(){
  Wire.begin();
  Wire.setClock(100000);
  Wire.beginTransmission(_adr);
  Wire.write(0B11000000);              // clear resister
  return Wire.endTransmission();
}

byte PT2258::clear_resister(){
  Wire.beginTransmission(_adr);
  Wire.write(0B11000000);              // clear resister
  return Wire.endTransmission();
}

byte PT2258::mute(boolean m,byte cha){
  byte c = ch(cha);
  byte mu;
  if(m==true)mu = 1; else if(m==0)mu=0;
  Wire.beginTransmission(_adr);
  Wire.write(0B11111000+mu);
  return Wire.endTransmission();

}

byte PT2258::setvolume(byte v, byte cha){
  clear_resister();
  byte one,ten = 0;
  if(v>79) v=79;
  v =79-v;
  ten = v/10;
  one = v%10;
  if(cha==0){
    Wire.beginTransmission(_adr);
    Wire.write(ch(cha)+0B00100000+one);
    Wire.write(ch(cha)+0B00010000+ten);
    return Wire.endTransmission();
  }
  else{
    Wire.beginTransmission(_adr);
    Wire.write(ch(cha)+0B00010000+one);
    Wire.write(ch(cha)+ten);
    return Wire.endTransmission();
  }
}
byte PT2258::setvolume_per(byte v, byte cha){
  clear_resister();
  byte one,ten = 0;
  if(v>100) v=100;
  v = map(v,0,100,0,79);
  v =79-v;
  ten = v/10;
  one = v%10;
  if(cha==0){
    Wire.beginTransmission(_adr);
    Wire.write(ch(cha)+0B00100000+one);
    Wire.write(ch(cha)+0B00010000+ten);
    return Wire.endTransmission();
  }
  else{
    Wire.beginTransmission(_adr);
    Wire.write(ch(cha)+0B00010000+one);
    Wire.write(ch(cha)+ten);
    return Wire.endTransmission();
  }
}
byte PT2258::ch(byte c){
  byte channal = 0;
  switch(c){
    case 1:
      channal = 0B10000000;
      break;
    case 2:
      channal = 0B01000000;
      break;
    case 3:
      channal = 0B00000000;
      break;
    case 4:
      channal = 0B00100000;
      break;
    case 5:
      channal = 0B01100000;
      break;
    case 6:
      channal = 0B10100000;
      break;
    case 0:
      channal = 0B11000000;
      break;
    default:
      channal = 0B11000000;
      break;
  }
  return channal;
}