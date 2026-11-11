/** ###################################################################
**     Filename  : Questao2.c
**     Project   : Questao2
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 09/11/2026, 23:09
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Questao2 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PortT.h"
#include "PortB.h"
#include "PortA.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include <math.h>
#include "Macros.h"

float x1 = 0;
float x2 = 0;
float delta = 0;
float x1Im = 0;
float x2Im = 0;
i8 a = 0;
i8 b = 0;
i8 c = 0;

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  
  //a = 2; b = 3; c = 2;
  
  a = (i8) getPort(PortA);
  b = (i8) getPort(PortB);
  c = (i8) getPort(PortT);
 
  if (a != 0){
    
    delta= (float) (b*b - 4.0f*a*c);
    
    if (delta == 0){
    // raizes reais iguais
        x1 = (float)((-b)/(2.0*a));
        x2 = x1;
        
    } else if (delta > 0){
        x1 = (float) ((-b + sqrt((double) delta))/(2.0f*a));
        x2 = (float) ((-b - sqrt((double) delta))/(2.0f*a));
    
    } else { // delta < 0
        delta *= -1;
        x1 = (float)((-b)/(2.0f*a));
        x2 = x1;
        x1Im = (float)((sqrt((double) delta))/(2.0f*a));
        x2Im = (float)(-(sqrt((double) delta))/(2.0f*a));
    }
  
  } else { // a = 0 e f(x) = bx + c
    
    if (b != 0) {
    
        x1 = (float)(-c) / (float)b;
        x2 = x1;
        
    } else { // f(x) = c
        x1 = 0; 
        x2 = 0;
    }
  
  } 
  
  
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END Questao2 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
