#define _XTAL_FREQ 8000000
#include <xc.h>

#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config PWRT = ON
#pragma config MCLRE = OFF
#pragma config LVP = OFF

int main(void)
{
    TRISD = 0;              // Todos os pinos como sa�da
    LATD = 0;               // Apaga todos os segmentos
    TRISA = 0xC3;           // RA2, RA3, RA4 e RA5 como sa�da
    LATA = 0xC3;            // Apaga todos os d�gitos

    while(1)
    {
        LATD = 0x06;        // C�digo do n�mero 1
        LATA = 0xC7;
        __delay_ms(500);    // Aguarda 500 ms
        LATA = 0xC3;
        LATD = 0x5B;        // C�digo do n�mero 2
        LATA = 0xCB;
        __delay_ms(500);    // Aguarda 500 ms
        LATA = 0xC3;
        LATD = 0x4F;        // C�digo do n�mero 3
        LATA = 0xD3;
        __delay_ms(500);    // Aguarda 500 ms
        LATA = 0xC3;
        LATD = 0x66;        // C�digo do n�mero 4
        LATA = 0xE3;
        __delay_ms(500);    // Aguarda 500 ms
        LATA = 0xC3;
    }
    return 0;
}    


