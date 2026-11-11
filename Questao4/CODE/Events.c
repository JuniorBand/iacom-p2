/** ###################################################################
**     Filename  : Events.c
**     Project   : Questao4
**     Processor : MC9S12C128CFU16
**     Component : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 11/11/2026, 09:34
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#pragma CODE_SEG DEFAULT

extern unsigned int duty_value_ms_1;
extern unsigned int duty_value_ms_2;


/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EInt1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void EInt1_OnInterrupt(void)
{
  /* place your EInt1 interrupt procedure body here */
  
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


/*
** ===================================================================
**     Event       :  Timer_1_OnInterrupt (module Events)
**
**     Component   :  Timer_1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Timer_1_OnInterrupt(void)
{
  /* Write your code here ... */

  // T1 = 500 ms
  // Inicia com duty_value_ms_1 = 50 -> 10%
  // Incrementa de 10% em 10% até 80%
    
  if (duty_value_ms_1 > 400){ // > 80%
    duty_value_ms_1 = 50; 
  }

  duty_value_ms_1 += 50;

  PWM_1_SetDutyMS(duty_value_ms_1);

}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
