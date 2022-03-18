    #include <io.h>
    
void main()
{
    #asm 
    .EQU DDRD=0x0A
    .EQU PORTC=8
    .EQU PINC=6
    .EQU PORTD=0x0B
    Inicio:
       LDI R16,0xFF    ;DDRD=0xFF en ensamblador
       OUT DDRD,R16    ;Salida en PD0 a PD7
       
       LDI R16, 0x0F   ;PORTC=0x0F en ensamblador
       OUT PORTC,R16   ;Pull up en PC0 a PC3
    Ciclo:
       IN R17,PINC     ;Obtiene los 8 bits del puerto C pero solo quieres los 4 menos significativos
       ANDI R17,0x0F   ;AND de 0x0F con PINC para solo tener los 4 bits menos significativos    
       CPI R17,0
       BREQ Es0
       CPI R17,1
       BREQ Es1
       CPI R17,2
       BREQ Es2
       CPI R17,3
       BREQ Es3
       CPI R17,4
       BREQ Es4
       CPI R17,5
       BREQ Es5
       CPI R17,6
       BREQ Es6
       CPI R17,7
       BREQ Es7
       CPI R17,8
       BREQ Es8
       CPI R17,9
       BREQ Es9
       CPI R17,0x0A
       BREQ EsA
       CPI R17,0x0B
       BREQ EsB
       CPI R17,0x0C
       BREQ EsC
       CPI R17,0x0D
       BREQ EsD
       CPI R17,0x0E
       BREQ EsE
    EsF:
      LDI R16,0x8E
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    Es0:
      LDI R16,0xFC
      OUT PORTD,R16   ;Asigna una 0 al Display
      RJMP Ciclo  
    Es1:
      LDI R16,0x60
      OUT PORTD,R16   ;Asigna una 1 al Display
      RJMP Ciclo 
    Es2:
      LDI R16,0xDB
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo
    Es3:
      LDI R16,0xF3
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    Es4:
      LDI R16,0x66
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    Es5:
      LDI R16,0xB7
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    Es6:
      LDI R16,0xBE
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    Es7:
      LDI R16,0xE1
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    Es8:
      LDI R16,0xFE
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    Es9:
      LDI R16,0xF6
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    EsA:
      LDI R16,0xEE
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    EsB:
      LDI R16,0x3F
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
    EsC:
      LDI R16,0x9C
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo
    EsD:
      LDI R16,0x7B
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo  
    EsE:
      LDI R16,0x9E
      OUT PORTD,R16   ;Asigna una F al Display
      RJMP Ciclo 
       
   #endasm    
}