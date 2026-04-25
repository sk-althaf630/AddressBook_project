#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

void delay (unsigned int ms, unsigned int speed)
{
    unsigned int i,j;
    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < speed; j++)
        {
            NOP();
        }
    }
}
void glow_on_press(unsigned char key)
{

	if (key == SWITCH1)
	{
        unsigned int i = 0; 
        unsigned int mode = 0;
        
		while(1)
        {
            delay(300,310);
            if(mode == 0)
            {
                LEDS = (0XFF >> (7-i)) & 0XFF;
                i++;
                if(i == 8)
                {
                    i = 0;
                    mode = 1;
                }
            }
            else if(mode == 1)
            {
                LEDS = (0XFF << i) & 0XFF;
                i++;
                if(i == 8)
                {
                    i = 0;
                    mode = 2;
                }
            }
            else if(mode == 2)
            {
                LEDS = (0XFF << (7 - i)) & 0XFF;
                i++;
                if(i == 8)
                {
                    i = 0;
                    mode = 3;
                }
            }
            else if(mode == 3)
            {
                LEDS = (0XFF >> i) & 0XFF;
                i++;
                if(i == 8)
                {
                    i = 0;
                    mode = 0;
                }
            }   
        }
	}
    else if(key == SWITCH2)
    {
        unsigned int i = 0; 
        unsigned int mode = 0;
        
        while(1)
        {
        }
    }
	else
	{
		LEDS = OFF;
	}

}

static void init_config(void)
{
	ADCON1 = 0x0F;

	LEDS = OFF;
	TRISB0 = 0;

	init_digital_keypad();
}

void main(void)
{
	unsigned char key;
	unsigned short i;

	init_config();

	while (1)
	{
		key = read_digital_keypad(LEVEL);
		glow_on_press(key);
		
	}
}



