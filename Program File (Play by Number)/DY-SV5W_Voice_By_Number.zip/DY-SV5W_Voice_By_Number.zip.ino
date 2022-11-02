#include <Arduino.h>
#include "DYPlayerArduino.h"

// Initialise the player, it defaults to using Serial.
DY::Player player;

// Alternatively initialise on another serial port.
// DY::Player player(&Serial2);

void setup() {
  player.begin();
  player.setVolume(30); // 50% Volume
  Serial.begin(9600);
  Serial.println("Starting......");
}

void loop() {
  if (Serial.available() > 0){
    char command = Serial.read();
    if (command == '1'){
      Serial.println("Music File - 1 Played");
      player.playSpecified(1);
      delay(5000);
    }
    else if (command == '2'){
      Serial.println("Music File - 2 Played");
      player.playSpecified(2);
      delay(5000);
    }
    else if (command == '3'){
      Serial.println("Music File - 3 Played");
      player.playSpecified(3);
      delay(5000);
    }
    else if (command == '4'){
      Serial.println("Music File - 4 Played");
      player.playSpecified(4);
      delay(5000);
    }
    else if (command == '5'){
      Serial.println("Music File - 5 Played");
      player.playSpecified(5);
      delay(5000);
    }
    else if (command == '6'){
      Serial.println("Music File - 6 Played");
      player.playSpecified(6);
      delay(5000);
    }
    else if (command == '7'){
      Serial.println("Music File - 7 Played");
      player.playSpecified(7);
      delay(5000);
    }
    else if (command == '8'){
      Serial.println("Music File - 8 Played");
      player.playSpecified(8);
      delay(5000);
    }
    else if (command == '9'){
      Serial.println("Music File - 9 Played");
      player.playSpecified(9);
      delay(5000);
    }
    else if (command == 'x'){
      Serial.println("Music File - 10 Played");
      player.playSpecified(10);
      delay(5000);
    }
  }
  else{
    Serial.println("No Command Given");
    }
//  player.playSpecified(10);
//  delay(5000);
}
