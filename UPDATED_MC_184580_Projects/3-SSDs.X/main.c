#include <xc.h>
#include "main.h"
#include "ssd_display.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

void init_config(void) {
    init_ssd_control();
}

void main(void) {
    init_config();
    unsigned int count = 0;
    unsigned int delay = 0;

    while (1) {


        ssd[3] = digit[count % 10];
        ssd[2] = digit[count / 10 % 10];
        ssd[1] = digit[count / 100 % 10];
        ssd[0] = digit[count / 1000];

        display(ssd);

        if (delay++ == 55) {
            count++;
            delay = 0;

            if (count > 9999) {
                count = 0;
            }
        }
    }
}