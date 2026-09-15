#define ECHO_PIN 2
#define TRIG_PIN 15
#define LED_BUILTIN 4

int LED_1 = 19;
int LED_2 = 18;
int LED_3 = 5;
int LED_4 = 17;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  int duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  if(distance > 50 && distance < 100) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  else if(distance > 100 && distance < 200) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  else if(distance > 200 && distance < 300) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);
  }
  else if(distance > 300) {
    Serial.println(distance);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  }
  else {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
  delay(10); // this speeds up the simulation
}
