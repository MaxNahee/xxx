#include <Arduino.h>
// กำหนดขา LED แต่ละดวง
const int led1 = 23;
const int led2 = 19;
const int led3 = 18;
const int led4 = 5;
const int led5 = 17;
const int led6 = 16;
const int led7 = 4;
const int led8 = 0;

// กำหนดขา potentiometer
const int potPin = 36;  // ขา A36 ที่เชื่อมต่อกับ potentiometer

void setup() {
  // ตั้งค่าขา LED เป็น output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  
  // ตั้งค่าขา potentiometer เป็น input
  pinMode(potPin, INPUT);
}

void loop() {
  // อ่านค่าจาก potentiometer (0-4095)
  int potValue = analogRead(potPin);
  
  // แปลงค่าจาก 0-4095 เป็น 0-100
  int mappedValue = map(potValue, 0, 4095, 0, 100);
  
  // คำนวณจำนวน LED ที่จะเปิด (จาก 0-100)
  int numLEDsToTurnOn = map(mappedValue, 0, 100, 0, 8);
  
  // เปิดหรือปิด LED ตามจำนวนที่คำนวณ
  if (numLEDsToTurnOn >= 1) digitalWrite(led1, HIGH);
  else digitalWrite(led1, LOW);
  
  if (numLEDsToTurnOn >= 2) digitalWrite(led2, HIGH);
  else digitalWrite(led2, LOW);
  
  if (numLEDsToTurnOn >= 3) digitalWrite(led3, HIGH);
  else digitalWrite(led3, LOW);
  
  if (numLEDsToTurnOn >= 4) digitalWrite(led4, HIGH);
  else digitalWrite(led4, LOW);
  
  if (numLEDsToTurnOn >= 5) digitalWrite(led5, HIGH);
  else digitalWrite(led5, LOW);
  
  if (numLEDsToTurnOn >= 6) digitalWrite(led6, HIGH);
  else digitalWrite(led6, LOW);
  
  if (numLEDsToTurnOn >= 7) digitalWrite(led7, HIGH);
  else digitalWrite(led7, LOW);
  
  if (numLEDsToTurnOn >= 8) digitalWrite(led8, HIGH);
  else digitalWrite(led8, LOW);
  
  delay(100);  // หน่วงเวลาเล็กน้อย
}

