    #include <io.h>
    
void main()
{
    #asm
    .EQU DDRD=0x0A
    .EQU PORTD=0x0B
    .EQU PINB=3
    .EQU PINC=6
    
    ;Configurar PD0 a PD7 de salida 
    LDI R16,0xFF
    OUT DDRD,R16
    
    
    
Ciclo:
    ;Leer operandos R24=A y R25=B
    IN R24,PINB                  
    ANDI R24,0x0F
    IN R25,PINB  
    SWAP R25       ;Intercambia los 4 bits más significativos por los menos significativos
    ANDI R25,0x0F  	
    ;Leer operador R22=Operador
    IN R22,PINC
    ANDI R22,0x07
    
    
	;Comparar Operador  
    CPI R22,0
    BREQ EsNOT
    CPI R22,1
    BREQ EsAND
    CPI R22,2 
    BREQ EsNAND
    CPI R22,3
    BREQ esOR
    CPI R22,4
    BREQ EsNOR
    CPI R22,5
    BREQ EsXOR
    CPI R22,6
    BREQ EsXNOR 
    ;Operaciones
Essuma:
    ADD R24,R25
    OUT PORTD,R24
    RJMP Ciclo
EsNOT:
    COM R24
    OUT PORTD,R24
    RJMP Ciclo
EsAND:
    AND R24,R25
    OUT PORTD,R24
    RJMP Ciclo
EsNAND:
    ADD R24,R25 
    COM R24
    OUT PORTD,R24
    RJMP Ciclo 
EsOR:
    OR R24,R25
    OUT PORTD,R24
    RJMP Ciclo  
EsNOR:
    OR R24,R25
    COM R24
    OUT PORTD,R24
    RJMP Ciclo
EsXOR:
    EOR R24,R25
    OUT PORTD,R24
    RJMP Ciclo
EsXNOR:
    EOR R24,R25
    COM R24
    OUT PORTD,R24
    RJMP Ciclo 
    
    #endasm
}