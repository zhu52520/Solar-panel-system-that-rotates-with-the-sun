
#include <Servo.h>

volatile int flag;
volatile int rota;
Servo servo_A3;
Servo servo_A2;

void setup(){
  flag = 1;
  rota = 1;
  servo_A3.attach(A3);
  servo_A2.attach(A2);
  while (true) {
    while (flag == 1) {
      if ((analogRead(A5) <= 200 && analogRead(A4) <= 200) && (analogRead(A1) <= 200 && analogRead(A0) <= 200)) {
        flag = 0;
        break;

      }
      if (analogRead(A5) > analogRead(A4) + 100) {
        servo_A3.write((servo_A3.read() + rota));
        delay(5);

      } else if (analogRead(A4) > analogRead(A5) + 100) {
        servo_A3.write((servo_A3.read() - rota));
        delay(5);
      }
      if (analogRead(A1) > analogRead(A0) + 50) {
        if (rota == 1 && servo_A2.read() < 100 || rota == -1 && servo_A2.read() >= 80) {
          servo_A2.write((servo_A2.read() + 1));
          delay(5);

        }

      } else if (analogRead(A0) > analogRead(A1) + 50) {
        if (rota == 1 && servo_A2.read() <= 100 || rota == -1 && servo_A2.read() > 80) {
          servo_A2.write((servo_A2.read() - 1));
          delay(5);

        }
      }
      if (servo_A3.read() == 180 && (servo_A2.read() >= 130 || servo_A2.read() <= 50)) {
        servo_A2.write((180 - servo_A2.read()));
        delay(750);
        servo_A3.write(5);
        delay(750);
        rota = rota * -1;

      }
      if (servo_A3.read() == 0 && (servo_A2.read() >= 130 || servo_A2.read() <= 50)) {
        servo_A2.write((180 - servo_A2.read()));
        delay(750);
        servo_A3.write(175);
        delay(750);
        rota = rota * -1;

      }
    }
    servo_A3.write(90);
    delay(7);
    servo_A2.write(90);
    delay(7);
    flag = 1;
  }
}

void loop(){

}