<<<<<<< HEAD

#define PIR 13
#define  LDR A1
#define BUZ 2
#define LED 3

void setup() {
  Serial.begin(9600);
  pinMode( PIR, INPUT);
  pinMode( LDR, INPUT);
  pinMode(BUZ, OUTPUT);

  

}

void loop() {
  int a=digitalRead(PIR);
  int b=analogRead(LDR);



  Serial.print("sensor PIR= ");
  Serial.println(a);
  Serial.print(" sensor LDR = ");
  Serial.println(b);
   
   if (a==1)
   {
    digitalWrite(LED,1);
   }
   else
   {

  digitalWrite( LED,0);
   }
  if(b>700)
  { 
   digitalWrite( BUZ ,1);
   delay(1000);
   digitalWrite( BUZ,0);

 }
  else
  {  
  digitalWrite( BUZ,0);
  }
 delay(1000);
=======

#define PIR 13
#define  LDR A1
#define BUZ 2
#define LED 3

void setup() {
  Serial.begin(9600);
  pinMode( PIR, INPUT);
  pinMode( LDR, INPUT);
  pinMode(BUZ, OUTPUT);

  

}

void loop() {
  int a=digitalRead(PIR);
  int b=analogRead(LDR);



  Serial.print("sensor PIR= ");
  Serial.println(a);
  Serial.print(" sensor LDR = ");
  Serial.println(b);
   
   if (a==1)
   {
    digitalWrite(LED,1);
   }
   else
   {

  digitalWrite( LED,0);
   }
  if(b>700)
  { 
   digitalWrite( BUZ ,1);
   delay(1000);
   digitalWrite( BUZ,0);

 }
  else
  {  
  digitalWrite( BUZ,0);
  }
 delay(1000);
>>>>>>> b364004 (initial commit)
}