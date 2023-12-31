#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led-sound.h"

void greenControl(int on)
{
  if (on) {
    P1OUT |= LED_GREEN;
  } else {
    P1OUT &= ~LED_GREEN;
  }
}

// State Machine for Green Light (Bright to Dim) and Buzzer (Low to High)
static int blinkLimit = 5;   //  state var representing reciprocal of duty cycle

void blinkUpdateG() // called every 1/250s to blink with duty cycle 1/blinkLimit
{
  // As long as the blink count does not pass the blink limit, the light will remain on.
  static int blinkCount = 0; // state var representing blink state
  blinkCount ++;
  //The buzzer's frequency corresponds with the blink count.
  buzzer_set_period( (1000 + (blinkCount*100)) );
  if (blinkCount >= blinkLimit) {
    blinkCount = 0;
    greenControl(1);
  }
  else
    greenControl(0);
}

/* Enables light to go from dim to bright by increasing duty cycle; the higher the duty cycle, the 
   brighter the light. */
void oncePerSecondG() // repeatedly start low and gradually increse duty cycle, one step/sec
{
  blinkLimit --;  // Increase duty cycle
  if (blinkLimit <= 0)  // but don't let duty cycle go above 1/7.
    blinkLimit = 8;
}

// Speed at which green light will brighten and buzzer will increase in frequency.
// In this case, each state of the buzzer and green light will remain for 6% of a second.
void secondUpdateG()
{
  static int secondCount = 0;
  secondCount ++;
  if (secondCount >= 15){
    secondCount= 0;
    oncePerSecondG();
  }
}

void greenTimeAdvStateMachines() // called every 1/250 sec
{
  blinkUpdateG();
  secondUpdateG();
}

