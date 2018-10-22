#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_MIN_PWM 60
#define L298N_ENA 3
#define L298N_ENB 9
#define L298N_IN1 4
#define L298N_IN2 2
#define L298N_IN3 7
#define L298N_IN4 8

class Motor {
private:
  int constrainPwm(int value) const {
    value = constrain(value, -255, 255);
    if (abs(value) <= MOTOR_MIN_PWM) {
      return 0;
    }

    return value;
  }

public:
  Motor() {
    // Setup H-Bridge
    pinMode(L298N_ENA, OUTPUT);
    pinMode(L298N_ENB, OUTPUT);
    pinMode(L298N_IN1, OUTPUT);
    pinMode(L298N_IN2, OUTPUT);
    pinMode(L298N_IN3, OUTPUT);
    pinMode(L298N_IN4, OUTPUT);

  }

  void setRight(int value) {
    if (value < 0) {
      digitalWrite(L298N_IN1, HIGH);
      digitalWrite(L298N_IN2, LOW);
    }
    else {
      digitalWrite(L298N_IN1, LOW);
      digitalWrite(L298N_IN2, HIGH);
    }
    value = constrainPwm(value);

    analogWrite(L298N_ENA, value);
  }

  void setLeft(int value) {
    if (value < 0) {
      digitalWrite(L298N_IN3, HIGH);
      digitalWrite(L298N_IN4, LOW);
    }
    else {
      digitalWrite(L298N_IN3, LOW);
      digitalWrite(L298N_IN4, HIGH);
    }

    value = constrainPwm(value);

    analogWrite(L298N_ENB, value);
  }

};

#endif //MOTOR_H
