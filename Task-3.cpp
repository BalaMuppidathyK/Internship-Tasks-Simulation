<<<<<<< HEAD
#define l1 4
#define sw1 13
#define sw2 12

void setup() {
pinMode(l1, OUTPUT);
pinMode(sw1, INPUT);
pinMode(sw2, INPUT);
}

void loop() {
  int s1 = digitalRead(sw1),s2 = digitalRead(sw2);

   if(s1==1&&s2==1)
  {
    digitalWrite(l1, 0);
  }
  if(s1==1&&s2==0)
  {
    digitalWrite(l1, 1);
  }
=======
#define l1 4
#define sw1 13
#define sw2 12

void setup() {
pinMode(l1, OUTPUT);
pinMode(sw1, INPUT);
pinMode(sw2, INPUT);
}

void loop() {
  int s1 = digitalRead(sw1),s2 = digitalRead(sw2);

   if(s1==1&&s2==1)
  {
    digitalWrite(l1, 0);
  }
  if(s1==1&&s2==0)
  {
    digitalWrite(l1, 1);
  }
>>>>>>> b364004 (initial commit)
  }