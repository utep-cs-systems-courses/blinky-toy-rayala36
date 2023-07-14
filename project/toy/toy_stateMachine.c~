#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led-sound.h"

void
switch_interrupt_handler()
{
  char p1val = P1IN;
  char p2val = P2IN;		/* switch is in P1 */

  /* update switch interrupt sense to detect changes from current buttons */ 
  P1IES |= (p1val & TOPSW);	 // if switch up, sense down 
  P1IES &= (p1val | ~TOPSW);	 //if switch down, sense up 
  
/* up=(Dim-to-Bright) green LED and (Low-to-High) buzz */
  if( p2val & TOPS1 ? 0 : 1 ){
    /* down=(Bright-to-Dim) red LED and (High-to-Low) buzz */
    greenTimeAdvStateMachines();
    P1OUT &= ~LED_RED;
  } else if( p2val & TOPS2 ? 0 : 1){
    redTimeAdvStateMachines();
    P1OUT &= ~LED_GREEN;
  } else if( p2val & TOPS3 ? 0 : 1){
    song();
    P1OUT |= ~LEDS;
  } else if( p2val & TOPS4 ? 0 : 1){
    song2();
    P1OUT &= ~LEDS;
  } else if (p1val & SW1 ? 0 : 1){
    siren();
  } else{
    buzzer_set_period(0);
    P1OUT &= ~LEDS;
  }
}
