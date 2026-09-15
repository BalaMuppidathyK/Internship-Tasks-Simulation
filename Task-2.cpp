#define l1 4
#define sw1 13
#define sw2 12
#define sw3 13
#define sw4 12
void setup() {
pinMode(l1, OUTPUT);
pinMode(sw1, INPUT);
pinMode(sw2, INPUT);
pinMode(sw3, INPUT);
pinMode(sw4, INPUT);
}

void loop() {
  int s1 = digitalRead(sw1),s2 = digitalRead(sw2),s3 = digitalRead(sw3),
  s4 = digitalRead(sw4);
   if(s1==1)
  {
    digitalWrite(l1, 1);
  }

  else{
    digitalWrite(l1,0);
   }
  if(s3==1)
  {
    digitalWrite(l1, 1);
  }

  else{
    digitalWrite(l1,0);
}
  if(s2==1)
  {
    digitalWrite(l1, 0);
  }

  else{
    digitalWrite(l1,1);
}
if(s4==1)
  {
    digitalWrite(l1, 0);
  }
  else{
    digitalWrite(l1,1);
  }
}
