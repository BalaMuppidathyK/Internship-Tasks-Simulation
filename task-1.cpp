#define l1 2
#define l2 3
#define l3 4
#define sw1 13
#define sw2 12
#define sw3 10
#define sw4 11
#define sw5 8
#define sw6 9

void setup() {
pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(sw1, INPUT);
pinMode(sw2, INPUT);
pinMode(sw3, INPUT);
pinMode(sw4, INPUT);
pinMode(sw5, INPUT);
pinMode(sw6, INPUT);
}

void loop() {
  int s1 = digitalRead(sw1),s2 = digitalRead(sw2),s3 = digitalRead(sw3),
  s4 = digitalRead(sw4),s5 = digitalRead(sw5),s6 = digitalRead(sw6);

  if(s1==1)
  {
    digitalWrite(l1, 1);
  }

  else{
    digitalWrite(l1,0);
  
   }
  if((s2||s3)==1)
  {
    digitalWrite(l2, 1);
  }

  else{
    digitalWrite(l2,0);
}
  if((s4&&s5)==1)
  {
    digitalWrite(l3, 1);
  }

  else{
    digitalWrite(l3,0);
}
if(s6==1)
  {
    digitalWrite(l1, 0);
    digitalWrite(l2, 0);
    digitalWrite(l3, 0);
  }
  
}
