<<<<<<< HEAD
#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(6);
}

void loop() {
  for(int i = 0;i<=180;i++){
    myservo.write(i);
    delay(50);
  }
  for(int i = 180;i>=0;i--){
    myservo.write(i);
    delay(50);
  }
  // put your main code here, to run repeatedly:
//myservo.write(90);
//delay(500);

//myservo.write(180);
//delay(600);

//myservo.write(0);
//delay(600);
=======
#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(6);
}

void loop() {
  for(int i = 0;i<=180;i++){
    myservo.write(i);
    delay(50);
  }
  for(int i = 180;i>=0;i--){
    myservo.write(i);
    delay(50);
  }
  // put your main code here, to run repeatedly:
//myservo.write(90);
//delay(500);

//myservo.write(180);
//delay(600);

//myservo.write(0);
//delay(600);
>>>>>>> b364004 (initial commit)
}