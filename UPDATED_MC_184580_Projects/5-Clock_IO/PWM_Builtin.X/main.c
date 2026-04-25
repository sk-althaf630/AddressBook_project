/*
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include "matrix_keypad.h"
#include "pwm.h"
#define MAX_DUTY              100

void pwm_control(unsigned char key) 
{
    static unsigned char duty_cycle = 50;
    static unsigned int wait = 100;
    
    if (!wait--)
    {
        wait = 100;
        
        if (key == MK_SW1)
        {
            if (duty_cycle != MAX_DUTY)
            {
                duty_cycle++;
            }
        } 
        else if (key == MK_SW2)
        {
            if (duty_cycle != 0)
            {
                duty_cycle--;
            }
        }
    }
    
    
    set_pwm_duty(duty_cycle); // 50%
}

static void init_config(void) 
{
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    TRISC2 = 0;
    init_matrix_keypad();
    init_pwm();
}

void main(void) 
{
    unsigned char key;
    
    init_config();

    while (1) 
    {
        key = read_switches(LEVEL);
        
        pwm_control(key);
        
    //    for (int i = 10000; i--; );
    }
    return;
}