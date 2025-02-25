#define _XTAL_FREQ 8000000
#include <xc.h>

#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config PWRT = ON
#pragma config MCLRE = OFF
#pragma config LVP = OFF

int main(void)
{
    TRISD = 0;
    LATD = 0;
    TRISA = 0xC3;
    LATA = 0x04;
    __delay_ms(1000);
  
    while (1)
    {
        LATD = 0x6F;
        __delay_ms(500);
        LATD = 0x7F;
        __delay_ms(500);
        LATD = 0x6F;
        __delay_ms(500);
        LATD = 0x06;
        __delay_ms(500);
        LATD = 0x7F;
        __delay_ms(500);
        
       /*
        LATA = 0x04;
        LATD = 0x6F;
        __delay_ms(20);
        LATA = 0x08;
        LATD = 0x7F;
        __delay_ms(20);
        LATA = 0x10;
        LATD = 0x6F;
        __delay_ms(20);
        LATA = 0x20;
        LATD = 0x06;
        __delay_ms(20);
        LATA = 0x40;
        LATD = 0x7F;
        __delay_ms(20);
        */
        
    }
    
    return 0;
}
