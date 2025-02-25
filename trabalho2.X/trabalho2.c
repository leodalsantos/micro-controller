#define _XTAL_FREQ 8000000

#define RS RE2
#define EN RE1
#define D0 RD0
#define D1 RD1
#define D2 RD2
#define D3 RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

#include <xc.h>
#include <stdbool.h>
#include "lcd.h";

#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config PWRT = ON
#pragma config MCLRE = OFF
#pragma config LVP = OFF

bool op;

void interrupt isr(void)  //void __interrupt () isr(void)
{
    if (INTCONbits.INT0IF && INTCONbits.INT0IE)
    {
        INTCONbits.INT0IF = 0;
        op = !op;
    }
}


int main (void)
{
    op = false;
    
    TRISD = 0x00;
    TRISE = 0xF9;
    TRISB = 0xFF;
    ADCON1 = 0xFF;
    
    Lcd_Init();
    Lcd_Clear();
    
    INTCONbits.INT0IE = 1; 
    INTCONbits.INT0IF = 0;       
    
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
    while (!op)
    {
        Lcd_Set_Cursor(1,2);
        Lcd_Write_String("Equipamento em");
        Lcd_Set_Cursor(2,5);
        Lcd_Write_String("Standby");
    }
    
    while (op)
    {
        Lcd_Set_Cursor(1,2);
        Lcd_Write_String("Entrando em");
        Lcd_Set_Cursor(2,2);
        Lcd_Write_String("operacao");          
    }
    
    return 0;
}

