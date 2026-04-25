#include <xc.h>
#include "clcd.h"

static void init_config(void)
{
    init_clcd();
  
}

void main(void)
{
    init_config();

    while (1)
    {
        clcd_putch('H', LINE1(0)); 
        clcd_print("abcd", LINE2(4)); 
    }
}