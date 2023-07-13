#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led-sound.h"

void redControl(int On)
{
  if (On) {
    P1OUT |= LED_RED;
  } else {
    P1OUT &= ~LED_RED;
  }
}

// State Machine for Red Light (Dim to Bright) and Buzzer (High to Low)
static int blinkLimit2 = 5;   //  state var representing reciprocal of duty cycle

void blinkUpdateR() // called every 1/250s to blink with duty cycle 1/blinkLimit
{
  static int blinkCount2 = 0; // state var representing blink state
  blinkCount2 ++;
  buzzer_set_period( (1000 + (blinkCount2*100)) );
  if (blinkCount2 >= blinkLimit2) {
    blinkCount2 = 0;
    redControl(1);
  }
  else
    redControl(0);
}

void oncePerSecondR() // repeatedly start bright and gradually lower duty cycle, one step/sec
{
  blinkLimit2 ++;  // Reduce duty cycle
  if (blinkLimit2 >= 8)  // but don't let duty cycle go below 1/7.
    blinkLimit2 = 0;
}

void secondUpdateR()
{
  static int secondCount2 = 0;
  secondCount2 ++;
  if (secondCount2 >= 30){
    secondCount2 = 0;
    oncePerSecondR();
  }
}

void redTimeAdvStateMachines() // called every 1/250 sec
{
  blinkUpdateR();
  secondUpdateR();
}
