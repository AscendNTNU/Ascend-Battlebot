#include "receiver.h"
#include "motor.h"

Receiver rx;
Motor motor;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read user input
  int ch1 = rx.readCh(0);
  int ch2 = rx.readCh(1);
  
  Serial.print(ch1);
  Serial.print(", ");
  Serial.print(ch2);
  Serial.println(", ");

  // apply control
  //motor.setRight(ch1 - ch2);
  //motor.setLeft(ch1 + ch2);
}
