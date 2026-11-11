/** ###################################################################
**     Filename  : Questao1.c
**     Project   : Questao1
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 09/11/2026, 21:57
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Questao1 */

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

i8 numero = 0;
u16 resultado = 0; // fatorial comum nao pode ser negativo
// (A porta B tem só 8 bits, ele é truncado a partir de 6!) 

i8 fatorial(i8 x, u16* res_fat);

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  //PortA_SetDir(0); // input
  //PortB_SetDir(1); // output

  while(1){
  
    numero = getPort(PortA); // getVal retorna byte (unsigned)

    if (fatorial(numero, &resultado)){
     
     writePort(PortB, resultado);
  
    } else {
    
     writePort(PortB, 0);
      
    }
  }
  

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/


i8 fatorial(i8 x, u16* res_fat){
  if (x < 0){
    return 0;
  }
  
  if (x == 0){
    *res_fat = 1;
    return 1;
  }       
  
  *res_fat = x;
  
  while (x > 1){
    *res_fat *= (x-1);
    
    x--;
  }
  
  return 1;
}


/* END Questao1 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
