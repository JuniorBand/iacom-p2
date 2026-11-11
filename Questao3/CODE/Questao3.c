/** ###################################################################
**     Filename  : Questao3.c
**     Project   : Questao3
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 09/11/2026, 23:08
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Questao3 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Potenciometro.h"
#include "PWM_OSC.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */


volatile unsigned int valorRV1 = 0; // Potenciometro

void gerarDutyCycle(volatile unsigned int* valorPWM);

void main(void)
{
  /* Write your local variable definition here */


  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  Potenciometro_Enable();
  Potenciometro_EnableEvent();
  Potenciometro_Start();
  PWM_OSC_Enable();
  

  while(1){
    gerarDutyCycle(&valorRV1);
  }
  

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/


void gerarDutyCycle(volatile unsigned int* valorPWM){

  // valorRV1 esta sendo atualizado pelo Events.c a cada 10 us
  // T = 1000 ms
  if (*valorPWM < 4096){ // (0-4095) 10% de Duty Cycle
  
    PWM_OSC_SetDutyMS(100);
    //PWM_OSC_SetRatio16(6554);// (0 - 65535) <=> (0% - 100%)

  
  } else if (*valorPWM < 8192){ // (4096-8191) 20% de Duty Cycle
  
    PWM_OSC_SetDutyMS(200);
    //PWM_OSC_SetRatio16(13108);      
  
  } else if (*valorPWM < 16384){ // (8192-16383) 30% de Duty Cycle
  
    PWM_OSC_SetDutyMS(300);
    //PWM_OSC_SetRatio16(19662);
  
  } else if (*valorPWM < 32767){ // (16384-32767) 40% de Duty Cycle
  
    PWM_OSC_SetDutyMS(400);
    //PWM_OSC_SetRatio16(26216);
  
  } else if (*valorPWM < 34815){ // (32768-34815) 50% de Duty Cycle
  
    PWM_OSC_SetDutyMS(500);
    //PWM_OSC_SetRatio16(32770);
  
  } else { // (34816-65535) 70% de Duty Cycle
  
    PWM_OSC_SetDutyMS(700);
    //PWM_OSC_SetRatio16(45878);
  
  }

  return;

}

/* END Questao3 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
