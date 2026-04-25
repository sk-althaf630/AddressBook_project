#include <xc.h>
#include "main.h"

#define PERIOD			1000

static void init_config(void)
{
	ADCON1 = 0x0F;

	PORTB=0;
	TRISB = 0;
	RB1 = 1;

}

void main(void)
{
	unsigned int duty_cycle = 50;
	unsigned int prog_cycle;

	init_config();

	while (1)
	{
		RB0= 1; /* CP is Clock Pin */
		for(prog_cycle = 100; prog_cycle--; );
		RB0 = 0; /* CP is Clock Pin */
		for(prog_cycle = 1000  ; prog_cycle--; );




	}

}
