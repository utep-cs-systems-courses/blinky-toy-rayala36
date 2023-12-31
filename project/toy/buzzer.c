#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

// Overall function: Controls the buzzer

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
  
    /*used to drive speaker by generating periodic interrupts; sets timer to Up mode*/
    timerAUpmode();

    /*Clears bits 6 and 7 of P2SELS2 register, ensuring they are not used for alternate functions*/
    P2SEL2 &= ~(BIT6 | BIT7);
    
    /* P2.7 is used as a GPIO pin. */
    P2SEL &= ~BIT7;

    /* Enables alternate fucntion of P2.6*/
    P2SEL |= BIT6;

    /* Configures P2.6 as an output pin to control the buzzer*/
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}


// Sets period of buzzer's tone by configuring the timer's Capture/Compare Registers(CCR0 and CCR1)
void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  // Determines total period of the tone.
  CCR0 = cycles;

  // Controls duty cycle of square wave generated by buzzer by setting CCR1 to 1/2 of the period.
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

