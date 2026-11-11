/** ###################################################################
**     Filename  : Questao4.c
**     Project   : Questao4
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 11/11/2026, 09:34
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
#include "Botao_SW1.h"
#include "PWM_1.h"
#include "PWM_2.h"
#include "Timer_1.h"
#include "EInt1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
unsigned int duty_value_ms_1 = 0;
unsigned int duty_value_ms_2 = 0;

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

  PWM_1_Enable();
  PWM_2_Enable();
  EInt1_Enable();
  Timer_1_Enable();
  Timer_1_EnableEvent();
  
  
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
