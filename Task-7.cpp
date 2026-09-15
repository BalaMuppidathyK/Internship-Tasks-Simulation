// ultrasonic 
#define   l1 2
#define   l2 3 
#define   buz 4


const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(buz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send a 10us pulse to TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);

  if ((distance >0) && (distance <=100)){
    digitalWrite(l1,1);
    digitalWrite(l2,LOW);
    digitalWrite(buz,LOW);
  }
  else if ((distance>100) &&( distance <=200)){
    digitalWrite(l1,0);
    digitalWrite(l2,1);
    digitalWrite(buz,0);
  }
  else if  (( distance > 200) && (distance <=300)) {

    digitalWrite(l2,0);
    digitalWrite(l1,0);
    digitalWrite(l2,0);
    digitalWrite(buz,1);
    
  }
  else  if (distance>300){
     digitalWrite(l1,0);
     digitalWrite(l2,0);
     digitalWrite(buz,1);
     delay(500);
     digitalWrite(buz,0);
  }

}