// EscControl.cpp

#include "ESC.h"

EscControl::EscControl(int pin) : escPin(pin) {}

//setup function
void EscControl::init() {
  //reference pin
  esc.attach(escPin);
  //send to esc 
  //esc.writeMicroseconds(1500);
}

//write esc values
void EscControl::updateEsc(int joystickValue) {
  //convert to esc range
  escValue = map(joystickValue, 0, 200, 1100, 1900);
  //send to esc
  esc.writeMicroseconds(escValue);
  Serial.println()
}

//get thruster values
int EscControl::getEscValue(){
  return escValue;
}
