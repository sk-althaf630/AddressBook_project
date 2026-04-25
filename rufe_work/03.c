#include <xc.h>
#include "header.h"

void main(void) 
{
//    unsigned int count = 0;
    extern unsigned int count;
    int flag = 0;
    init_config();
    
    while(1)
    {
       
        unsigned char key;
       
        key = read_digital_keypad(EDGE);
        
        if(flag == 1)
        {
          PATTERN1();  
        }
        
        else if(flag == 2)
        {
            PATTERN2();
        }
        
        else if(flag == 3)
        {
            PATTERN3();
        }
        else if(flag == 4)
        {
            PATTERN4();
        }
        
        
        
        
        
        if(key == SWITCH1)
        {
           flag = 1;
           count = 0;
        }
        else if(key == SWITCH2)
        {
           flag = 2;
           count = 0;
        }
        else if(key == SWITCH3)
        {
           flag = 3;
           count = 0;
           PORTB = 0xAA; 
        }
        else if(key == SWITCH4)
        {
          flag = 4;
          count = 0;
          PORTB = 0xF0; 
        }
    }
    
    return;
}