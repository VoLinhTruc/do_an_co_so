#include "Arduino.h"
#include "Bico_Led7Seg_HC595.h"

#define GREEN_1   2
#define YELLOW_1  3
#define RED_1     4
#define GREEN_2   5
#define YELLOW_2  6
#define RED_2     7

#define LIGHT_ON 0
#define LIGHT_OFF 1

class Traffic_Light
{
  public:
    Traffic_Light();
    void begin();
    void run();

    uint8_t g_t; //green_time
    uint8_t y_t; //yellow_time
    uint8_t r_t; //red_time
    uint8_t c_t1; //counting_time
    uint8_t c_t2; //counting_time

    uint8_t g_l1; //green_light
    uint8_t y_l1; //yellow_light
    uint8_t r_l1; //red_light
    uint8_t g_l2; //green_light
    uint8_t y_l2; //yellow_light
    uint8_t r_l2; //red_light

  private:
  
};

Traffic_Light::Traffic_Light()
{
    g_t = 10; //green_time
    y_t = 2; //yellow_time
    r_t = 12; //red_time
    c_t1 = 0; //counting_time1
    c_t2 = 0; //counting_time2

    g_l1 = GREEN_1; //green_light
    y_l1 = YELLOW_1; //yellow_light
    r_l1 = RED_1; //red_light
    g_l2 = GREEN_2; //green_light
    y_l2 = YELLOW_2; //yellow_light
    r_l2 = RED_2; //red_light
}

void Traffic_Light::begin()
{
  pinMode(g_l1, OUTPUT);
  pinMode(y_l1, OUTPUT);
  pinMode(r_l1, OUTPUT);
  pinMode(g_l2, OUTPUT);
  pinMode(y_l2, OUTPUT);
  pinMode(r_l2, OUTPUT);
}

void Traffic_Light::run()
{
  digitalWrite(g_l1, LIGHT_ON);
  digitalWrite(r_l2, LIGHT_ON);

  digitalWrite(y_l1, LIGHT_OFF);
  digitalWrite(r_l1, LIGHT_OFF);
  digitalWrite(g_l2, LIGHT_OFF);
  digitalWrite(y_l2, LIGHT_OFF);

  c_t1 = g_t;
  c_t2 = r_t;

  for(int i = g_t; i > 0; i--)
  {
    Serial.write(c_t1);
    
    Serial.write(c_t2);
    c_t1 -= 1;
    c_t2 -= 1;
    delay(1000);
  }
  //---------------------------
  
  digitalWrite(y_l1, LIGHT_ON);
  digitalWrite(r_l2, LIGHT_ON);

  digitalWrite(g_l1, LIGHT_OFF);
  digitalWrite(r_l1, LIGHT_OFF);
  digitalWrite(g_l2, LIGHT_OFF);
  digitalWrite(y_l2, LIGHT_OFF);

  c_t1 = y_t;
  
  for(int i = y_t; i > 0; i--)
  {
    Serial.write(c_t1);
    
    Serial.write(c_t2);
    c_t1 -= 1;
    c_t2 -= 1;
    delay(1000);
  }
  //---------------------------
  
  digitalWrite(r_l1, LIGHT_ON);
  digitalWrite(g_l2, LIGHT_ON);

  digitalWrite(g_l1, LIGHT_OFF);
  digitalWrite(y_l1, LIGHT_OFF);
  digitalWrite(y_l2, LIGHT_OFF);
  digitalWrite(r_l2, LIGHT_OFF);

  c_t1 = r_t;
  c_t2 = g_t;

  for(int i = g_t; i > 0; i--)
  {
    Serial.write(c_t1);
    
    Serial.write(c_t2);
    c_t1 -= 1;
    c_t2 -= 1;
    delay(1000);
  }
  //---------------------------
  
  digitalWrite(r_l1, LIGHT_ON);
  digitalWrite(y_l2, LIGHT_ON);

  digitalWrite(g_l1, LIGHT_OFF);
  digitalWrite(y_l1, LIGHT_OFF);
  digitalWrite(g_l2, LIGHT_OFF);
  digitalWrite(r_l2, LIGHT_OFF);

  c_t2 = y_t;

  for(int i = y_t; i > 0; i--)
  {
    Serial.write(c_t1);
    
    Serial.write(c_t2);
    c_t1 -= 1;
    c_t2 -= 1;
    
    delay(1000);
  }
}

Traffic_Light cot_den_1;

void setup() {
  // put your setup code here, to run once:
  cot_den_1.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  cot_den_1.run();
}
