#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <ESP32Servo.h>

// Pin definitions
#define DHTPIN 4
#define DHTTYPE DHT22
#define SOIL_MOISTURE_PIN 34
#define RELAY_PIN 18
#define LDR_PIN 35
#define SERVO_PIN 5

// Threshold values
const int moistureThreshold = 2000;
const int lightThreshold = 1500;

// Components
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo shadingServo;

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Greenhouse");
  shadingServo.attach(SERVO_PIN);
  shadingServo.write(0);
  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
  int lightLevel   = analogRead(LDR_PIN);
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  // Irrigation control
  if (soilMoisture < moistureThreshold) {
    digitalWrite(RELAY_PIN, LOW);   // Water pump ON
    lcd.setCursor(0,1);
    lcd.print("Pump: ON  ");
  } else {
    digitalWrite(RELAY_PIN, HIGH);  // Water pump OFF
    lcd.setCursor(0,1); 
    lcd.print("Pump: OFF ");
  }

  // Shading control
  if (lightLevel > lightThreshold) 
  {
    shadingServo.write(90);  // Close shade
  }
  else 
  {
    shadingServo.write(0);   // Open shade
  }

  // Serial output
  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print(" Hum: ");  Serial.print(humidity);
  Serial.print(" Soil: "); Serial.println(soilMoisture);

  delay(2000);
}
