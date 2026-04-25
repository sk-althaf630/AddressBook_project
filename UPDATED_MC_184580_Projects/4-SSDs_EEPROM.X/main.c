#include <xc.h>
#include "main.h"
#include "ssd_display.h"
#include"digital_keypad.h"
#include "eeprom.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
int i = 0, j = 0, k = 0, l = 0;
void init_config(void)
{
	init_ssd_control();
   
	i = read_internal_eeprom(0x00);
    j = read_internal_eeprom(0x01);
    k = read_internal_eeprom(0x02);
    l = read_internal_eeprom(0x03);
	 
}

void main(void)
{
	init_config();
    unsigned char key;
    unsigned int wait = 0;
	while(1)
	{
        key = read_digital_keypad(STATE_CHANGE);
        if(key == SWITCH1)
        {
            write_internal_eeprom(0x00, i);
            write_internal_eeprom(0x01, j);
            write_internal_eeprom(0x02, k);
            write_internal_eeprom(0x03, l);
        }
        
        //logic
        if(wait++ == 300)
        {
            wait = 0;
            if(i++ == 10)
            {
                i = 0;
                if(j++ == 10)
                {
                    j = 0;
                    if(k++ == 10)
                    {
                        k = 0;
                        if(l++ == 10)
                        {
                            l = 0;
                        }
                    }
                }
            }
        }
		ssd[3] = digit[i];
		ssd[2] = digit[j];
		ssd[1] = digit[k];
		ssd[0] = digit[l];
        
		display(ssd);
	}
}