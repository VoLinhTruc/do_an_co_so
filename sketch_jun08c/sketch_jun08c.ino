#include "Bico_Led7Seg.h"

Bico_Led7Seg display(COMMON_ANODE, 2, 1000, 0);

uint8_t digit[3] = {10, 11};
uint8_t code[8] = {2, 3, 4, 5, 6, 7, 8, 9};

uint8_t c_t1 = 0;
uint8_t c_t2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial3.begin(9600);
  Serial.begin(9600);

  display.setup(digit, code);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial3.available() > 0)
  {
    delay(5);
    c_t1 = Serial3.read();
    c_t2 = Serial3.read();

    Serial.print(c_t1);
    Serial.print('\t');
    Serial.println(c_t2);


  }
    display.setDigit(0, c_t1%10, false);
    display.setDigit(1, c_t1/10, false);
    display.show();
}
