#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led-sound.h"

void song(){
  static int buzzTime = 0;
  buzzTime++;
  if (buzzTime == 50){
      buzzer_set_period(1000);
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_RED;
  } else if (buzzTime == 100){
      buzzer_set_period(1000);
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_GREEN;
      
  } else if (buzzTime == 150){
      buzzer_set_period(800);
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      
  } else if (buzzTime == 200){
      buzzer_set_period(1000);
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_RED;
      
  } else if (buzzTime == 325){
      buzzer_set_period(800);
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      
  } else if (buzzTime == 450){
      buzzer_set_period(700);
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_RED;
      
  } else if (buzzTime == 575){
      buzzer_set_period(600);
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
  } else if (buzzTime == 700){
      buzzer_set_period(600);
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      
  } else if (buzzTime == 750){
      buzzer_set_period(800);
      P1OUT |= LED_GREEN;
      P1OUT &= ~LED_RED;
      
  } else if (buzzTime == 850){
      buzzer_set_period(600);
      P1OUT |= LED_RED;
      P1OUT &= ~LED_GREEN;
      
  } else if (buzzTime == 900)
       buzzTime = 0; 
}
