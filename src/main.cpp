// Library version:1.1.5
// Example of picking custom I2C pins on ESP32

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define I2C_SDA 21
#define I2C_SCL 22

LiquidCrystal_I2C lcd(0x27, 20, 4); // ตั้งค่าที่อยู่ของ LCD

// กำหนดขาเชื่อมต่อ
int leds[8] = {23, 22, 21, 19, 18, 17, 16, 4};  // LED 8 หลอด
int sw_next = 15; // ปุ่ม Next
int sw_ok = 2;    // ปุ่ม OK

int menu = 0;

void setup() {
  lcd.init(I2C_SDA, I2C_SCL); // กำหนดขา SDA และ SCL
  lcd.backlight();  // เปิดไฟแบ็คไลท์ของ LCD

  // กำหนดขา LED เป็น OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);  // เริ่มต้นด้วยการปิด LED
  }

  pinMode(sw_next, INPUT_PULLUP); // กำหนดปุ่ม Next เป็น INPUT_PULLUP
  pinMode(sw_ok, INPUT_PULLUP);   // กำหนดปุ่ม OK เป็น INPUT_PULLUP
}

void loop() {
  int status_next = digitalRead(sw_next); // อ่านสถานะปุ่ม Next

  if (status_next == LOW) {  // ถ้ากดปุ่ม Next
    menu++;
    if (menu > 5) {  // เมื่อถึงเมนูสุดท้ายให้กลับไปที่เมนูแรก
      menu = 0;
    }
    delay(200);  // หน่วงเวลา
  }

  // แสดงเมนูที่เลือกบน LCD
  lcd.clear();  // ล้างหน้าจอก่อน
  lcd.setCursor(0, 0);
  lcd.print("Menu: ");
  lcd.print(menu + 1);  // แสดงหมายเลขเมนูที่เลือก

  switch (menu) {
    case 0:
      // เมนู 1: LED ทั้ง 8 หลอดเปิดพร้อมกัน
      lcd.setCursor(0, 1);
      lcd.print("LED All ON");
      for (int i = 0; i < 8; i++) {
        digitalWrite(leds[i], HIGH);  // เปิด LED ทั้ง 8 หลอด
      }
      break;

    case 1:
      // เมนู 2: LED กระพริบสลับกัน (คู่-คี่)
      lcd.setCursor(0, 1);
      lcd.print("LED Blink Odd/Even");
      for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
          digitalWrite(leds[i], HIGH);  // เปิด LED คู่
        } else {
          digitalWrite(leds[i], LOW);   // ปิด LED คี่
        }
      }
      delay(500);
      for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
          digitalWrite(leds[i], LOW);   // ปิด LED คู่
        } else {
          digitalWrite(leds[i], HIGH);  // เปิด LED คี่
        }
      }
      delay(500);
      break;

    case 2:
      // เมนู 3: LED สว่างทีละหลอดวนไปเรื่อย ๆ
      lcd.setCursor(0, 1);
      lcd.print("LED Chase");
      for (int i = 0; i < 8; i++) {
        digitalWrite(leds[i], HIGH);  // เปิด LED ทีละหลอด
        delay(200);
        digitalWrite(leds[i], LOW);   // ปิด LED
      }
      break;

    case 3:
      // เมนู 4: LED ติดเป็นคู่ (2 หลอดในเวลาเดียวกัน)
      lcd.setCursor(0, 1);
      lcd.print("LED Pair ON");
      for (int i = 0; i < 8; i += 2) {
        digitalWrite(leds[i], HIGH);   // เปิด LED คู่
        digitalWrite(leds[i + 1], HIGH);
      }
      break;

    case 4:
      // เมนู 5: LED สว่างเรียงลําดับจากหลอดแรกถึงหลอดสุดท้ายและดับกลับทีละหลอด
      lcd.setCursor(0, 1);
      lcd.print("LED Sequence ON/OFF");
      for (int i = 0; i < 8; i++) {
        digitalWrite(leds[i], HIGH);  // เปิด LED ตามลำดับ
        delay(200);
      }
      for (int i = 7; i >= 0; i--) {
        digitalWrite(leds[i], LOW);   // ปิด LED ตามลำดับ
        delay(200);
      }
      break;

    case 5:
      // เมนู 6: LED กระพริบทั้งหมดพร้อมกัน
      lcd.setCursor(0, 1);
      lcd.print("LED All Blink");
      for (int i = 0; i < 8; i++) {
        digitalWrite(leds[i], HIGH);  // เปิด LED ทั้งหมด
      }
      delay(500);
      for (int i = 0; i < 8; i++) {
        digitalWrite(leds[i], LOW);   // ปิด LED ทั้งหมด
      }
      delay(500);
      break;
  }

  // ตรวจสอบการกดปุ่ม OK เพื่อยืนยันการเลือกเมนู
  int status_ok = digitalRead(sw_ok);
  if (status_ok == LOW) {
    // เมื่อกดปุ่ม OK สามารถทำอะไรเพิ่มเติมได้ (ในกรณีนี้ไม่ทำอะไร)
    delay(200);  // หน่วงเวลา
  }

  delay(200);  // หน่วงเวลา
}