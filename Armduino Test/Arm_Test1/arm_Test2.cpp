#include <iostream>
#include <stdexcept>
int wristValue = 90;
int clawValue = 90;
int wrist(int increase, int decrease) {
  // increase == 1, decrease == 0: increase wrist value
  // increase == 0, decrease == 1: decrease wrist value
  // increase == 1, decrease == 1: do nothing
  // increase == 0, decrease == 0: do nothing
  return (increase && !(decrease) && wristValue < 180) ? ++wristValue : ((decrease && !(increase) && wristValue > 0) ? --wristValue : wristValue);
}

int claw(int close, int open){
  // open == 1, close == 0: increase claw value
  // open == 0, close == 1: decrease claw value
  // open == 1, close == 1: do nothing
  // open == 0, close == 0: do nothing
  return (open && !(close) && clawValue < 180) ? ++clawValue : ((close && !(open) && clawValue > 0) ? --clawValue : wristValue);
}

int main(){
  printf("starting singular tests\n");
  int increasing, decreasing, closing, opening;
  printf("testing wrist\n");
  increasing = 1; decreasing = 1;
  printf("increasing = 1; decreasing = 1; %d\n", wrist(increasing, decreasing));
  increasing = 0; decreasing = 1;
  printf("increasing = 0; decreasing = 1; %d\n", wrist(increasing, decreasing));
  increasing = 1; decreasing = 0;
  printf("increasing = 1; decreasing = 0; %d\n", wrist(increasing, decreasing));
  increasing = 0; decreasing = 0;
  printf("increasing = 0; decreasing = 0; %d\n", wrist(increasing, decreasing));

  printf("\ntesting claw\n");
  opening = 1; closing = 1;
  printf("opening = 1; closing = 1; %d\n", claw(closing, opening));
  opening = 0; closing = 1;
  printf("opening = 0; closing = 1; %d\n", claw(closing, opening));
  opening = 1; closing = 0;
  printf("opening = 1; closing = 0; %d\n", claw(closing, opening));
  opening = 0; closing = 0;
  printf("opening = 0; closing = 0; %d\n", claw(closing, opening));

  printf("\n\nstarting loop tests");
  for (int i=0; i<10; i++){
    wrist(0, 1);
  }
  printf("wrist value after decreasing 10: %d\n", wristValue);

  for (int i=0; i<10000; i++){
    wrist(0, 1);
  }
  printf("wrist value after decreasing 10000: %d\n\n", wristValue);

  for (int i=0; i<10; i++){
    wrist(1, 0);
  }
  printf("wrist value after increasing 10: %d\n", wristValue);

  for (int i=0; i<10000; i++){
    wrist(1, 0);
  }
  printf("wrist value after increasing 10000: %d\n\n", wristValue);

  for (int i=0; i<10000; i++){
    wrist(0, 0);
  }
  printf("wrist value after doing nothing 10000 times: %d\n\n", wristValue);

  for (int i=0; i<10000; i++){
    wrist(1, 1);
  }
  printf("wrist value after doing nothing 10000 times: %d\n\n", wristValue);
}

/*
expected output: 

starting singular tests
testing wrist
increasing = 1; decreasing = 1; 90
increasing = 0; decreasing = 1; 89
increasing = 1; decreasing = 0; 90
increasing = 0; decreasing = 0; 90

testing claw
opening = 1; closing = 1; 90
opening = 0; closing = 1; 89
opening = 1; closing = 0; 90
opening = 0; closing = 0; 90


starting loop testswrist value after decreasing 10: 80
wrist value after decreasing 10000: 0

wrist value after increasing 10: 10
wrist value after increasing 10000: 180

*/