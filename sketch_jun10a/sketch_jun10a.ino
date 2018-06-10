void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial3.available() > 0)
  {
    char c0;
    char c1;
    char c2;
    char c3;
    
    delay(10);
    c0 = Serial3.read();
    Serial.write(c0); 
    c1 = Serial3.read();
    Serial.write(c1); 
    c0 = Serial3.read();
    Serial.write(c0); 
    c0 = Serial3.read();
    Serial.write(c0); 

    Serial3.write(0x00);
    Serial3.write(0x02);
    Serial3.write(0x09);
    Serial3.write(0xDD);
  }
}
