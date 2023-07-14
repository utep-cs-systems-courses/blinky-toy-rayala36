#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led-sound.h"

void song2(){  
  
  static int buzzTime2 = 0;
  buzzTime2++;
  if (buzzTime2 == 125)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(592);
  if (buzzTime2 == 250)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(0);
  if (buzzTime2 == 300)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(592);
  if (buzzTime2 == 425)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(705);
  if (buzzTime2 == 490)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(790);

  
  if (buzzTime2 == 550)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(592);
  if (buzzTime2 == 675)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(0);
  if (buzzTime2 == 825)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(592);
  
  if (buzzTime2 == 950)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(530);
  if (buzzTime2 == 1015)
    for(int x = 0; x < 25; x++)
      buzzer_set_period(560);
  
  if (buzzTime2 == 1020)
    buzzTime2 = 0;
  
}  

