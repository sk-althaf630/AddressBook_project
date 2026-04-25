#include <xc.h>
#include "main.h"

#define PERIOD			1000

static void init_config(void)
{
	ADCON1 = 0x0F;

	TRISB0 = 0;
}

void main(void)
{
	unsigned long prog_cycle, duty_cycle = 500;

	init_config();

	while (1)
	{
		RB0= 1; /* CP is Clock Pin */
		for(prog_cycle = duty_cycle; prog_cycle--; );
		RB0 = 0; /* CP is Clock Pin */
		for(prog_cycle = PERIOd - duty_cycle; prog_cycle--; );
		
		if (RC0 == 0)
		{
			if (duty_cycle != 1000)
			{
				duty_cycle++;
			}
		}
		if (RC1 == 0)
		{
			if (duty_cycle != 0)
			{
				duty_cycle--;
			}
		}

//		for(j = 50000; j--;);
	}

}
