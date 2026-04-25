#include <xc.h>

unsigned char  key_detected;

void __interrupt() isr(void)
{
	if (INT0F == 1)
	{
		key_detected = 1;

		INT0F = 0;
	}
}