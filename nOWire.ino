/**************************************************************************
* nOWire, Copyright (C) 2022 Juno Presken
* E-mail: juno.presken+github@protonmail.com
*
* This program is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation, either version 3 of the License, or (at your
* option) any later version.

* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.

* You should have received a copy of the GNU General Public License
* along with this program. If not, see <https://www.gnu.org/licenses/>.
*
**************************************************************************/
#include <SparkFun_OWire_Arduino_Library.h>

OWIRE led;

uint8_t myColor = OW_OFF;

void setup() {
  pinMode(0,OUTPUT);
  pinMode(1,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  led.begin(0,false);
  led.setModeAndColor(OW_SOLID, OW_OFF);

  int mode = jankRead(A2) * 10;
  mode += jankRead(A3); 

  int color = jankRead(A1)*100; 
  if(digitalRead(1)) color += 10;
  color += jankRead(A0);

  switch(color){
    case 1:
      myColor = OW_RED;
      break;
    case 2:
      myColor = OW_GREEN;
      break;
    case 11:
      myColor = OW_YELLOW;
      break;
    case 12:
      myColor = OW_BLUE;
      break;
    case 101:
      myColor = OW_VIOLET;
      break;
    case 102:
      myColor = OW_CYAN;
      break;
    case 111:
      myColor = OW_WHITE;
      break;
    case 201:
      myColor = OW_FULLCOLOR;
      break;
    case 202:
      myColor = OW_RGW;
      break;
    case 211:
      myColor = OW_RBW;
      break;
    case 212:
      myColor = OW_SIXCOLOR;
      break;
  }

  switch(mode){
    case 0:
      led.setMode(OW_SOLID);
      break;
    case 1:
      led.setMode(OW_8SECONDFADE);
      break;
    case 2:
      led.setMode(OW_WHITESPARKLES_SLOW);
      break;
    case 10:
      led.setMode(OW_WAVEFADE);
      break;
    case 11:
      led.setMode(OW_COLORSPARKLES_SLOW);
      break;
    case 12:
      led.setMode(OW_WHITESPARKLES_FAST);
      break;
    case 20:
      led.setMode(OW_COLORBLINKS);
      break;
    case 21:
      led.setMode(OW_COLORSPARKLES_FAST);
      break;
    case 22:
      cbat();
      break;
  }

  led.setColor(myColor);

}

void loop(){}

void cbat(){
  int intervals[] = {0,306,515,1118,1485,1680,1891,2245};
  int duration = 140;
  
  int cloffset = 0;
  
  while(true){
    for(int i=0; i<8; i++){
      if(i == 7) duration = 386;
      else duration = 140;
      if(millis() < 1000) cloffset = millis();
      while(((millis()-cloffset) % 2960) > intervals[i] && ((millis()-cloffset) % 2960) < (intervals[i] + duration)){
        if(led.getColor() != myColor)
          led.setColor(myColor);
      }
      if(led.getColor() != OW_OFF && i == 0)  //enforce idempotency on state, but only on i=0 because otherwise it breaks stuff for unknown reasons
        led.setColor(OW_OFF);
    }
  }
}

//without delay:

//beat every 0.375 seconds

//takes 1000 samples 2 see if the pin dips at all as a janky test of whether it's floating
//returns 0 if low, 1 if high, 2 if floating
byte jankRead(byte pin){
  byte result = 0;
  for(int i=0; i<1000; i++){
    if(analogRead(pin) < 100)
      result = 0;
    else if(analogRead(pin) == 1023)
      result = 1;
    else
      return 2;
  }
  return result;
}
