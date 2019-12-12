#include "N76E003.h"
#include "SFR_Macro.h"
#include "define.h"
//#include "common.h"
#include "dht11.h"
#include "delay.h"

//#define DATA DHT11_DATA
sbit DATA = P1^2;

void delay_ms(int n)
{
		Timer0_Delay1ms(n);
}
void DELAY_US(int n)
{
	while(n--){_nop_();_nop_();_nop_();}
}

unsigned char dht11_read(unsigned char *out)
{
    uint8_t     i;
    uint8_t     j;
    uint8_t     k;
    uint8_t     p;
    uint8_t     c;

    if (DATA) {
        DATA = 0;
        delay_ms(18);
    }

    DATA = 1;

    for (k = 100; k != 0; k--) {
        if (!DATA) {
            break;
        }
        DELAY_US(1);
    }
    for (k = 100; k != 0; k--) {
        if (DATA) {
            break;
        }
        DELAY_US(1);
    }

    p = 0;
    c = 0;
    for (i = 5; i != 0; i--, out++) {
        for (j = 8; j != 0; j--) {
            for (k = 100; k != 0; k--) {
                if (!DATA) {
                    break;
                }
                DELAY_US(1);
            }
            for (k = 100; k != 0; k--) {
                if (DATA) {
                    break;
                }
                DELAY_US(1);
            }
            DELAY_US(28);
            c = (c << 1) | DATA;
        }
        if (i > 1) {
            *out = c;
            p += c;
        }
    }

    for (k = 100; k != 0; k--) {
        if (!DATA) {    
            break;
        }
        DELAY_US(1);
    }

    return (c == p) ? 0 : DHT11_ERR_CHECKSUM;
}
