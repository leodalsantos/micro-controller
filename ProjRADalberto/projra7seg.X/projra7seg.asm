    LIST P=18F4520
    #include<P18F4520.INC>
    
    CONFIG	OSC=INTIO67, PWRT=ON, WDT=OFF, MCLRE=OFF, DEBUG=OFF
    
    
    
R0	EQU 0x00
R1	EQU 0x01
R2	EQU 0x02
	
    org		0x0000
    GOTO	INICIO
    org		0x0100

INICIO:
    MOVLW	0x78
    MOVWF	OSCCON
    MOVLW	0X0F
    MOVWF	ADCON1
    
    CLRF	TRISD
    CLRF	TRISA
    
    MOVLW	0x04
    MOVWF	LATA
D1:
    MOVLW	0x6F
    MOVWF	LATD
    CALL	delay500
    CLRF	LATD
    CALL	delay50
    SETF	LATD
    CALL	delay500
    CLRF	LATD
    CALL	delay50
    MOVLW	0x6F
    MOVWF	LATD
    CALL	delay500
    CLRF	LATD
    CALL	delay50
    MOVLW	0x06
    MOVWF	LATD
    CALL	delay500
    CLRF	LATD
    CALL	delay50
    SETF	LATD
    CALL	delay500
    CLRF	LATD
    CALL	delay500
    CALL	delay500
    ;CALL	delay500
    ;CALL	delay500
    BRA		D1
    
delay50:
    MOVLW	.10
    MOVWF	R2
DEC_R2:
    MOVLW	.130
    MOVWF	R1
DEC_R1:
    MOVLW	0xFF
    MOVWF	R0
DEC_R0:
    DECFSZ	R0
    BRA		DEC_R0
    DECFSZ	R1
    BRA		DEC_R1
    DECFSZ	R2
    BRA		DEC_R2
    RETURN
    
delay500:
    MOVLW	.20
    ;MOVLW	.10
    MOVWF	R2
DEC__R2:
    MOVLW	.130
    MOVWF	R1
DEC__R1:
    MOVLW	0xFF
    MOVWF	R0
DEC__R0:
    DECFSZ	R0
    BRA		DEC__R0
    DECFSZ	R1
    BRA		DEC__R1
    DECFSZ	R2
    BRA		DEC__R2
    RETURN
    
    END
    
    
    
    
    

