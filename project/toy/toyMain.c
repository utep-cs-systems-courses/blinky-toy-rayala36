#include <msp430.h>
#include "libTimer.h"
#include "led-sound.h"
#include "buzzer.h"

int main() {

  //Establishes timing system for MSP430 board 
    configureClocks();
  //Establishes response capabilities within board
    enableWDTInterrupts();

  //Sets output bits in bottom board to the LED light bits
    P1DIR |= LEDS;
  //Both lights are initially off.
    P1OUT &= ~LEDS;

  //Resistors in bottom board are enabled
    P1REN |= SWITCHES;
  //Interrupts are enabled in bottom board  
    P1IE |= SWITCHES;

    /* Enabling interrupt flags allows the microcontroller to respond to specific events or 
       conditions immediately by executing the corresponding ISR code. It helps the microcontroller
       handle time-sensitive tasks and respond to external events effectively, without constantly 
       checking for changes in the program flow. */

    P2REN |= TOPSW;
    P2IE |= TOPSW;
    
    // Buzzer is initialized.    
    buzzer_init();

    or_sr(0x18);          // CPU off, GIE on
}

void toy_stateMachine();

/*Both the bottom and top ports will implement the toy's state machine in order to present the 
  appropriate light/sound patterns when a button is pressed. */

/* Buttons on P2*/
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & TOPSW) {
    P2IFG &= ~TOPSW;
    toy_stateMachine();
  }
}

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    toy_stateMachine();
  }
}

/* The WDT will implement the toy's state machine in order to display the appropriate patterns at 
   the appropriate times for the appropriate amounts of time. */

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  toy_stateMachine();
}
