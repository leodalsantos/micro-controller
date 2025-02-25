    LIST P=18F4520
    #include<P18F4520.INC>
    
    ;Configuration Bits
    CONFIG  OSC=INTIO67,PWRT=ON,WDT=OFF,MCLRE=OFF,DEBUG=OFF
    
    org	    0x0000
    GOTO INICIO
    
    org 0x0008
TRATA_INT:
    ;BTFSS   INTCON,TMR0IE
    ;BRA	    FIM_INT
    ;BTFSS   INTCON,TMR0IF
    ;BRA	    FIM_INT
    BCF	    INTCON,TMR0IF
    BTFSC   LATB,0
    BRA	    CLEAR_LED
SET_LED:
    BSF	    LATB,0
    BRA	    FIM_INT
CLEAR_LED:
    BCF	    LATB,0
FIM_INT:
    RETFIE
    
    org	    0x0100
INICIO:
    MOVWF   0x78
    MOVLW   OSCCON
    MOVLW   0X0F
    MOVLW   ADCON1
    CLRF    TRISB
    CLRF    LATB
    MOVLW   0x04
    MOVWF   T0CON
    ;BCF	    T0CON,7
    ;BCF	    T0CON,6
    ;BCF	    T0CON,5
    ;BCF	    T0CON,4
    ;BCF	    T0CON,3
    ;BCF	    T0CON,2
    ;BSF	    T0CON,1
    ;BSF	    T0CON,0
    
    
    
    CLRF    TMR0H
    CLRF    TMR0L
    BCF	    INTCON,TMR0IF
    BSF	    INTCON,TMR0IE
    BSF	    INTCON,GIE
    BSF	    T0CON,TMR0ON
    
    ;CLRF    TRISD
    ;CLRF    TRISA
    ;CLRF    LATA
    ;CLRF    LATD
    
    
REPETE:
    BRA REPETE
    END
    


