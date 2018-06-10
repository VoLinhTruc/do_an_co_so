#include "Arduino.h"

#include "Bico_Led7Seg_HC595.h"
#include "Traffic_Light.h"


uint8_t traffic_7seg_digit[] = {0, 1, 2, 3, 4, 5, 6, 7};
uint8_t traffic_7seg_code[] = {8, 9, 10, 11, 12, 13, 14, 15};


Traffic_Light cot_den_1;
Bico_Led7Seg_HC595 seconds_display(COMMON_ANODE, 4, 1, 0, TRAFFIC_DATA_PIN, TRAFFIC_CLOCK_PIN, MSBFIRST, TRAFFIC_SS_PIN);


 INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
{
  seconds_display.setDigit(0, cot_den_1.getC_t1()/10, false);
  seconds_display.setDigit(1, cot_den_1.getC_t1()%10, false);
  seconds_display.setDigit(2, cot_den_1.getC_t2()/10, false);
  seconds_display.setDigit(3, cot_den_1.getC_t2()%10, false);
  seconds_display.show();
  /* Cleat Interrupt Pending bit */
  TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
}

void setup() {
  // put your setup code here, to run once:
  cot_den_1.begin();
  Serial.begin(9600);
  seconds_display.setup(traffic_7seg_digit, traffic_7seg_code);
  
  /* TIM4 configuration:
   - TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
   clock used is 16 MHz / 128 = 125 000 Hz
  - With 125 000 Hz we can generate time base:
      max time base is 2.048 ms if TIM4_PERIOD = 255 --> (255 + 1) / 125000 = 2.048 ms
      min time base is 0.016 ms if TIM4_PERIOD = 1   --> (  1 + 1) / 125000 = 0.016 ms
  - In this example we need to generate a time base equal to 1 ms
   so TIM4_PERIOD = (0.001 * 125000 - 1) = 124 */

  /* Time base configuration */
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124);
  /* Clear TIM4 update flag */
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  /* Enable update interrupt */
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  
  /* enable interrupts */
  enableInterrupts();

  /* Enable TIM4 */
  TIM4_Cmd(ENABLE);
}

void loop() {
  // put your main code here, to run repeatedly:
  cot_den_1.run();
}