#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led-sound.h"

void siren(){
  static int secondCount = 0;
    secondCount ++;
    if (secondCount <= 25) { 	/* once each sec... */
       P1OUT |= LED_GREEN;
       P1OUT &= ~LED_RED;
       buzzer_set_period(1000);
    } else if (secondCount == 50)
         secondCount = 0;
    else {
       P1OUT |= LED_RED;
       P1OUT &= ~LED_GREEN;
       buzzer_set_period(1500);
    }
}
