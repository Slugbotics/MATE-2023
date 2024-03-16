#include <Ethernet.h>
#include <EthernetUdp.h>
#include <Servo.h>

// Ethernet settings
byte mac[] = {  
  0xA8, 0x61, 0x0A, 0xAE, 0x95, 0xE3 };
IPAddress ip(192, 168, 1, 177);
unsigned int localPort = 8888;

// Initialize the Ethernet and UDP
EthernetUDP Udp;

// Arm Servos
Servo horizontalServo;
Servo verticalServo;

Servo wristServo;
Servo clawServo;

// Other output pins (replace with your pin numbers)
int wristValue = 90;
int clawValue = 90;

void setup() {
  // Start Ethernet and UDP
  Ethernet.begin(mac, ip);
  Udp.begin(localPort);

  // Attach servos to pins
  horizontalServo.attach(/*pin undecided*/);
  verticalServo.attach(/*pin undecided*/);

  wristServo.attach(/*pin undecided*/);
  clawServo.attach(/*pin undecided*/);

  // Setup other outputs
  pinMode(otherOutputPin, OUTPUT);
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    // Receive packet
    char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);

    // Parse packet
    int horizontal, vertical, wrist_decrease, wrist_increase, claw_close, claw_open;
    sscanf(packetBuffer, "[%*d], %*d, %*d, %*d, %*d, %*d, %*d, [%*d], %d, %d, %d, %d, %d, %d",
     &horizontal, &vertical, &wrist_decrease, &wrist_increase, &claw_close, &claw_open);

    // Control servos
    horizontalServo.write(horizontal);
    verticalServo.write(vertical);

    wristServo.write(wrist(wrist_decrease, wrist_increase));
    clawServo.write(claw(claw_close, claw_open));
  }
}

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