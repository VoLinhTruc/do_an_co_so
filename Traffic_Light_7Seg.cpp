#include "Arduino.h"

#include "Bico_Led7Seg.h"

Bico_Led7Seg display(COMMON_ANODE, 4, 1000, 0);

uint8_t digit[4] = {PD4, PA1, PA2, PA3};
uint8_t code[8] = {PC3, PC4, PC5, PC6, PC7, PD1, PD2, PD3};

uint8_t c_t1 = 0;
uint8_t c_t2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  display.setup(digit, code);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    delay(5);
    c_t1 = Serial.read();
    c_t2 = Serial.read();
  }
    display.setDigit(0, c_t1%10, false);
    display.setDigit(1, c_t1/10, false);
    
    display.setDigit(2, c_t2%10, false);
    display.setDigit(3, c_t2/10, false);
    
    display.show();
}