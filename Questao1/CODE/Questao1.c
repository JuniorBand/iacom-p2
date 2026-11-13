/** ###################################################################
**     Filename  : Fatoria_1l.c
**     Project   : Fatoria_1l
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 11/11/2026, 22:08
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Fatoria_1l */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PortA.h"
#include "PortB.h"
#include "Bit1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Macros.h"

i8 valor = 0;
u8 resultado = 0;
u8 fatorial = 0;
u8 i = 0;

void calcularFatorial(void);

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  while(1){
    calcularFatorial();
  }

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

void calcularFatorial(void){
  
    /* Leitura dos botoes */
    resultado = getPort(PortA);

    /* Inversao devido ao pull-up */
    resultado = ~resultado;

    /* Interpretacao em complemento de dois */
    valor = (i8)resultado;

    /* Verifica o valor */
    if(valor >= 0){
        fatorial = 1;

        for(i = 1; i <= valor; i++)
        {
            fatorial = fatorial * i;
        }
    }
    else
    {
        fatorial = 255;
    }

    /* Envia resultado aos LEDs */
    writePort(PortB, fatorial);
}

/* END Fatoria_1l */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
