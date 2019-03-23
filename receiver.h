#ifndef RECEIVER_H
#define RECEIVER_H

#include "EnableInterrupt/EnableInterrupt.h"

#define RX_N_CHANNELS 2
#define RX_IN_CH1 11
#define RX_IN_CH2 10
#define RX_IN_MIN 978
#define RX_IN_MAX 1990

volatile unsigned long rise_start[RX_N_CHANNELS];
volatile unsigned long pwm_value[RX_N_CHANNELS];


void ch1Setup();
void ch1Rising();
void ch1Falling();
void ch1Setup() {
    pinMode(RX_IN_CH1, INPUT); digitalWrite(RX_IN_CH1, LOW);
    enableInterrupt(RX_IN_CH1, &ch1Rising, RISING);
}
void ch1Rising() {
    rise_start[0] = micros();
    enableInterrupt(RX_IN_CH1, &ch1Falling, FALLING);
}
void ch1Falling() {
    pwm_value[0] = micros() - rise_start[0];
    enableInterrupt(RX_IN_CH1, &ch1Rising, RISING);
}

void ch2Setup();
void ch2Rising();
void ch2Falling();
void ch2Setup() {
    pinMode(RX_IN_CH2, INPUT); digitalWrite(RX_IN_CH2, LOW);
    enableInterrupt(RX_IN_CH2, &ch2Rising, RISING);
}
void ch2Rising() {
    rise_start[1] = micros();
    enableInterrupt(RX_IN_CH2, &ch2Falling, FALLING);
}
void ch2Falling() {
    pwm_value[1] = micros() - rise_start[1];
    enableInterrupt(RX_IN_CH2, &ch2Rising, RISING);
}


class Receiver {
public:
  Receiver() {
    ch1Setup();
    ch2Setup();
  }

  int readCh(unsigned int ch) {
    if (ch >= RX_N_CHANNELS || pwm_value[ch] == 0) {
      return 0;
    }

    return map(pwm_value[ch], RX_IN_MIN, RX_IN_MAX, -255, 255);
  }
};




#endif //RECEIVER_H
