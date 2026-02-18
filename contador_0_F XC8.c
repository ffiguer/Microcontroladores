Les dejo el programa: /*
* File: main.c
* Author: temp2
*
* Created on 29 de enero de 2026, 07:56 AM
*/
#include "config.h"
#include <xc.h>
int num =0;
void main(void)
{
//puertos a configurar
ADCON1 = 0x0F; //siempre configurar
//TRISB=0x01;//una entrada (1 son entradas, ceros son salidas)
TRISD=0x00; // todo el puerto D como salida
for (;;){
switch(num)
{
case 0: LATD=63;__delay_ms(300); break;
case 1: LATD=6;__delay_ms(300); break;
case 2: LATD=91;__delay_ms(300); break;
case 3: LATD=79;__delay_ms(300); break;
case 4: LATD=102;__delay_ms(300); break;
case 5: LATD=109;__delay_ms(300); break;
case 6: LATD=125;__delay_ms(300); break;
case 7: LATD=7;__delay_ms(300); break;
case 8: LATD=127;__delay_ms(300); break;
case 9: LATD=111;__delay_ms(300); break;
case 10: LATD=119;__delay_ms(300); break;
case 11: LATD= 127;__delay_ms(300); break;
case 12: LATD= 57;__delay_ms(300); break;
case 13: LATD= 63;__delay_ms(300); break;
case 14: LATD= 121;__delay_ms(300); break;
case 15: LATD= 113;__delay_ms(300); break;
}
num=num+1;
if(num==16)
{
num=0;
}
}
}
