/** ###################################################################
**     Filename  : Questao4.c
**     Project   : Questao4
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 10/11/2026, 20:13
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Questao4 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PWM_1.h"
#include "PWM_2.h"
#include "Botao_SW1.h"
#include "EInt1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

unsigned int duty_value_ms_1;
unsigned int duty_value_ms_2;

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  PWM_1_Enable();
  PWM_2_Enable();


  while(1){
extern unsigned int duty_value_ms_1;
extern unsigned int duty_value_ms_2;

  // T1 = 500 ms
  // Inicia com duty_value_ms_1 = 50 -> 10%
  // Incrementa de 10% em 10% até 80%
   
  if(duty_value_ms_1 > 400){ // > 80%
    duty_value_ms_1 = 50; 
  }

  duty_value_ms_1 += 50;

  PWM_1_SetDutyMS(duty_value_ms_1);
  
  // T2 = 1000 ms
  // Inicia com duty_value_ms_1 = 100 -> 10%
  // Incrementa de 20% em 20% até 90%
  char botaoPressionado = (char) !Botao_SW1_GetVal();
  
  if(duty_value_ms_2 > 900){
     duty_value_ms_2 = 100;
  }
  
  if(botaoPressionado){
    duty_value_ms_2 += 200;    
  }
  
  PWM_2_SetDutyMS(duty_value_ms_2);

  }

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END Questao4 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
