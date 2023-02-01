#include <SoftwareSerial.h>
#include <Arduino.h>
#include "DYPlayerArduino.h"
DY::Player player;

// The serial connection to the GPS module
SoftwareSerial ss(3, 11);
bool main_ = false;
String str_arr;
String emot;
String voc;
String data_arr[12];
int pointer = 0;
int s9 = A0;
int s8 = A1;
int s7 = A2;
int s6 = A3;
int s5 = A4;
int s4 = A5;
int s3 = A6;
int s2 = A7;


void setup() {
  delay(2000);
  player.begin();
  player.setVolume(5);  // 50% Volume

  ss.begin(115200);
  delay(1000);
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);

}
void pinstate() {
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
  digitalWrite(A6, HIGH);
  digitalWrite(A7, HIGH);
}
void loop() {
  pinstate();
  while (!ss.available());
  int incomingByte = ss.read();
  String stringOne = String(incomingByte, HEX);
  str_arr += stringOne + " ";

  if (str_arr.indexOf("d d e") > 0) {
    // Serial.print("Found :");
    // Serial.println(str_arr);
    main_ = true;
    pointer = 0;
    str_arr = "";
  }
  if (pointer == 9) {
    if (stringOne != voc) {

      Serial.println(stringOne);
      if (stringOne == "5") {
        digitalWrite(s5, LOW);
        delay(300);
      } else if (stringOne == "a") {
        digitalWrite(s9, LOW);
        delay(200);
      } else if (stringOne == "12") {
        digitalWrite(s6, LOW);
        delay(200);
      } else if (stringOne == "3") {
        digitalWrite(s7, LOW);
        delay(200);
      }
      voc = stringOne;
    }
  }
  pointer++;
}
