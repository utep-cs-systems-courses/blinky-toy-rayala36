	#include <msp430.h>

	#include "libTimer.h"

	#include "buzzer.h"

	#include "led-sound.h"



song2:

	mov.b &buzzTime2, r5

	inc.b r5

	cmp.b #125, r5

	jne song2_skip1

	mov #25, r6

song2_loop1:

	mov #592, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop1

song2_skip1:

	cmp.b #250, r5

	jne song2_skip2

	mov #25, r6

song2_loop2:

	mov #0, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop2

song2_skip2:

	cmp.b #300, r5

	jne song2_skip3

	mov #25, r6

song2_loop3:

	mov #592, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop3

song2_skip3:

	cmp.b #425, r5

	jne song2_skip4

	mov #25, r6

song2_loop4:

	mov #705, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop4

song2_skip4:

	cmp.b #490, r5

	jne song2_skip5

	mov #25, r6

song2_loop5:

	mov #790, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop5

song2_skip5:

	cmp.b #550, r5

	jne song2_skip6

	mov #25, r6

song2_loop6:

	mov #592, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop6

song2_skip6:

	cmp.b #675, r5

	jne song2_skip7

	mov #25, r6

song2_loop7:

	mov #0, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop7

song2_skip7:

	cmp.b #825, r5

	jne song2_skip8

	mov #25, r6

song2_loop8:

	mov #592, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop8

song2_skip8:

	cmp.b #950, r5

	jne song2_skip9

	mov #25, r6

song2_loop9:

	mov #530, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop9

song2_skip9:

	cmp.b #1015, r5

	jne song2_skip10

	mov #25, r6

song2_loop10:

	mov #560, r4

	call #buzzer_set_period

	dec.b r6

	jnz song2_loop10

song2_skip10:

	cmp.b #1020, r5

	jne song2_exit

	clr.b &buzzTime2

song2_exit:

	  ret
