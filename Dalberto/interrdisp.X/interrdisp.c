#define _XTAL_FREQ 8000000
#include <xc.h>

#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config PWRT = ON
#pragma config MCLRE = OFF
#pragma config LVP = OFF

#define ZERO    0x3F
#define UM      0x06
#define DOIS    0x5B
#define TRES    0x4F
#define QUATRO  0x66
#define CINCO   0x6D
#define SEIS    0x7D
#define SETE    0x07
#define OITO    0x7F
#define NOVE    0x6F

#define AUX     0x00

#define APAGADO 0xC3
#define DIS1    0xC7
#define DIS2    0xCB
#define DIS3    0xD3
#define DIS4    0xE3

int d1, d2, d3, d4, aux;

void interrupt isr(void)
{
     if(INTCONbits.T0IE && INTCONbits.T0IF)
     {
         INTCONbits.T0IF = 0;
         switch (LATA)
         {
             case DIS1:
                 LATA = APAGADO;
                 LATD = d2;
                 LATA = DIS2;
             break;
             
             case DIS2:
                LATA = APAGADO;
                LATD = d3;
                LATA = DIS3;
             break;
             
             case DIS3:
                LATA = APAGADO;
                LATD = d4;
                LATA = DIS4;
             break;
             
             case DIS4:
                LATA = APAGADO;
                LATD = d1;
                LATA = DIS1;
             break;
         }
     }    
}

int main(void)
{
    TRISD = 0;              // Todos os pinos como saída
    LATD = 0;               // Apaga todos os segmentos
    TRISA = 0xC3;           // RA2, RA3, RA4 e RA5 como saída
    LATA = 0xC3;            // Apaga todos os dígitos
    OSCCON = 0x78;          // Oscilador interno para 8 MHz
    ADCON1 = 0x0F;          // Todas as entradas analógicas como I/O digital
    T0CON = 0x45;           // 8 bits, clock do sistema, com prescaler (1:32) 
    INTCONbits.T0IF = 0;    // Zera Interrupt Flag do Timer0
    INTCONbits.T0IE = 1;    // Habilita interrupção do Timer0
    INTCONbits.GIE = 1;     // Habilita interrupção geral
    T0CONbits.TMR0ON = 1;   // Dispara Timer0
    LATAbits.LA5 = 1;       // Inicia com dígito 4 ativo
    
    d1 = UM;
    d2 = DOIS;
    d3 = TRES;
    d4 = QUATRO;
    
    while(1)
    {
        aux = d1;
        d1 = d2;
        d2 = d3;
        d3 = d4;
        d4 = aux;
        __delay_ms(1000);
    }
    return 0;
}
