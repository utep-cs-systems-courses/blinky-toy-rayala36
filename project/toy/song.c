#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led-sound.h"

void song(){
  static int buzzTime = 0;
  buzzTime++;
  if (buzzTime == 50)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(1000);
  if (buzzTime == 100)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(1000);
  if (buzzTime == 150)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(800);
  if (buzzTime == 200)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(1000);

  if (buzzTime == 325)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(800);
  if (buzzTime == 450)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(700);
  if (buzzTime == 575)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(600);
  
  if (buzzTime == 700)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(600);
  if (buzzTime == 750)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(800);
  if (buzzTime == 850)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(600);
  
  if (buzzTime == 900)
    buzzTime = 0; 
}
