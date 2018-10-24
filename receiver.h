#ifndef RECEIVER_H
#define RECEIVER_H

#include <EnableInterrupt.h>

#define RX_N_CHANNELS 2
#define RX_IN_CH1 11
#define RX_IN_CH2 10
#define RX_IN_MIN 978
#define RX_IN_MAX 1990

volatile unsigned long rise_start[RX_N_CHANNELS];
volatile unsigned long pwm_value[RX_N_CHANNELS];


#define ADD_CHANNEL(CH) \
  void ch##CH##Setup();\
  void ch##CH##Rising();\
  void ch##CH##Falling();\
  void ch##CH##Setup() {\
      pinMode(RX_IN_CH##CH, INPUT); digitalWrite(RX_IN_CH##CH, LOW);\
      enableInterrupt(RX_IN_CH##CH, &ch##CH##Rising, RISING);\
  }\
  void ch##CH##Rising() {\
      rise_start[CH - 1] = micros();\
      enableInterrupt(RX_IN_CH##CH, &ch##CH##Falling, FALLING);\
  }\
  void ch##CH##Falling() {\
      pwm_value[CH - 1] = micros() - rise_start[CH - 1];\
      enableInterrupt(RX_IN_CH##CH, &ch##CH##Rising, RISING);\
  }


ADD_CHANNEL(1);

ADD_CHANNEL(2);

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
