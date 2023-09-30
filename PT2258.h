#ifndef PT2258_h
#define PT2258_h

#include <Arduino.h>
#include <Wire.h>

class PT2258{
  public:
  PT2258(boolean a, boolean b);
  byte pt_begin();
  byte clear_resister();
  byte mute(boolean m,byte cha);
  byte setvolume(byte v,byte cha);
  byte setvolume_per(byte v, byte cha);
  private:
  byte _adr;
  byte ch(byte c);
};

#endif