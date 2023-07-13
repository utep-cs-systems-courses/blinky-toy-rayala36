#include <msp430.h>
#include "libTimer.h"
#include "led-sound.h"
#include "buzzer.h"

int main() {

    configureClocks();
    enableWDTInterrupts();

    P1DIR |= LEDS;
    P1OUT &= ~LEDS;

    P1REN |= SWITCHES;
    P1IE |= SWITCHES;
    P1OUT |= SWITCHES;
    P1DIR &= ~SWITCHES;
    P1IFG &= ~SWITCHES;

    P2IFG &= ~TOPSW;
    P2DIR &= ~TOPSW;
    P2REN |= TOPSW;
    P2IE |= TOPSW;
    P2OUT |= TOPSW;
    
    buzzer_init();

    or_sr(0x18);          // CPU off, GIE on
}

void switch_interrupt_handler();

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & TOPSW) {
    P2IFG &= ~TOPSW;
    switch_interrupt_handler();
  }
}

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/*250 interrupts/sec*/
{
  switch_interrupt_handler();
}
