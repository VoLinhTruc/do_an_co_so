#include "Arduino.h"

#define BUTTON PD1
#define BUZZER PC4

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  
  Serial.begin(9600);  // start serial for output
}

void loop() {
  if(Serial.available() > 0)
  {
    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(BUZZER, LOW);
    
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
  
  if(!digitalRead(BUTTON))
  {
    delay(300);
    
    //Address
    Serial.write((char)0x00);
    Serial.write((char)0x02);
    
    //Channel
    Serial.write((char)0x09);
    
    //Data
    Serial.write((char)0x10);
  }
}