#include <DHT.h>

#define DHTPIN 2         // Pin DHT11 terhubung ke pin digital 2
#define DHTTYPE DHT11    // Jenis sensor DHT

const int ldrPin = A0;     // Pin LDR terhubung ke pin analog A0
const int pirPin = 3;      // Pin PIR terhubung ke pin digital 3

const int led1Pin = 4;     // Pin LED 1 terhubung ke pin digital 4
const int led2Pin = 5;     // Pin LED 2 terhubung ke pin digital 5
const int led3Pin = 6;     // Pin LED 3 terhubung ke pin digital 6
const int buzzerPin = 7;   // Pin buzzer terhubung ke pin digital 7

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
  
  pinMode(pirPin, INPUT);
  
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Membaca suhu dan kelembaban dari sensor DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Membaca nilai LDR
  int ldrValue = analogRead(ldrPin);
  
  // Membaca status PIR
  int pirStatus = digitalRead(pirPin);
  
  // Menyalakan LED berdasarkan suhu yang ditentukan
  if (temperature >= 30.0) {
    digitalWrite(led1Pin, HIGH);
  } else {
    digitalWrite(led1Pin, LOW);
  }
  
  if (temperature >= 35.0) {
    digitalWrite(led2Pin, HIGH);
  } else {
    digitalWrite(led2Pin, LOW);
  }
  
  if (temperature >= 40.0) {
    digitalWrite(led3Pin, HIGH);
  } else {
    digitalWrite(led3Pin, LOW);
  }
  
  // Memeriksa gerakan yang terdeteksi oleh PIR
  if (pirStatus == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
  
  // Menampilkan data suhu, kelembaban, dan nilai LDR pada Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.print(" *C, Kelembaban: ");
  Serial.print(humidity);
  Serial.print("%, Nilai LDR: ");
  Serial.println(ldrValue);
  
  delay(1000);
}
