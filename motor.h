#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_MIN_PWM 70
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

    return value;
  }

  void writeToMotor(int value, int enable, int in1or3, int in2or4) {
    if (abs(value) < MOTOR_MIN_PWM){
      // disable motors to avoid drawing power when it can't spin
      digitalWrite(in1or3, LOW);
      digitalWrite(in2or4, LOW);
      return;
    }

    if (value < 0) {
      digitalWrite(in1or3, HIGH);
      digitalWrite(in2or4, LOW);
    }
    else {
      digitalWrite(in1or3, LOW);
      digitalWrite(in2or4, HIGH);
    }
    value = constrainPwm(value);

    analogWrite(enable, value);
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
    writeToMotor(value, L298N_ENA, L298N_IN1, L298N_IN2);
  }

  void setLeft(int value) {
    writeToMotor(value, L298N_ENB, L298N_IN3, L298N_IN4);
  }
};

#endif //MOTOR_H
