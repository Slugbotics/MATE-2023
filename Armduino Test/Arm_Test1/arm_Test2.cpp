#include <iostream>
#include <stdexcept>

void wrist(int decrease, int increase) {
  // increase == 1, decrease == 0: increase wrist value
  // increase == 0, decrease == 1: decrease wrist value
  // increase == 1, decrease == 1: do nothing
  // increase == 0, decrease == 0: do nothing
  return (increase && !decrease) ? wristValue++ : ((decrease && !increase) ? wristValue-- : wristValue);
}

void claw(int close, int open){
  // open == 1, close == 0: increase claw value
  // open == 0, close == 1: decrease claw value
  // open == 1, close == 1: do nothing
  // open == 0, close == 0: do nothing
  return (open && !close) ? clawValue++ : ((close && !open) ? clawValue-- : clawValue);
}

int main(){
  for (int i=0; i < 10000000000; i++){

  }
}