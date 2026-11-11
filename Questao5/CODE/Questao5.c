/** ###################################################################
**     Filename  : Questao5.c
**     Project   : Questao5
**     Processor : MC9S12C128CFU16
**     Version   : Driver 01.14
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 09/11/2026, 23:50
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Questao5 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "B0.h"
#include "P0.h"
#include "B1.h"
#include "B2.h"
#include "B3.h"
#include "B4.h"
#include "B5.h"
#include "B7.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Macros.h"

#define  BotaoI !P(B0)
#define  nivelA !P(P0)
#define  nivelB !P(B1)
#define  nivelC !P(B2)
#define  nivelD !P(B3)
#define  Evs P(B4)
#define  Eve P(B5)
#define erro_flag P(B7)
#define ligar(pino)    ((pino) = 1)
#define desligar(pino) ((pino) = 0)
    
static u8 botao_atual = 0;
static u8 sensA = 0;
static u8 sensB = 0;
static u8 sensC = 0;
static u8 sensD = 0;

volatile u8 erro_detectado = 0;
volatile u8 time_flag = 0;
volatile u8 estado_sistema = 0;
volatile u8 estado_anterior_botao = 0;

short _verificar_niveis(void);


void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

  while (1){
  
    _verificar_niveis();
  
  }

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/




short _verificar_niveis(void){
    
    botao_atual = !P(B0);
	  sensA = !P(P0);
    sensB = !P(B1);
    sensC = !P(B2);
    sensD = !P(B3);
    
    // Botao apertado e antes não apertado -> entra
    if (botao_atual && !estado_anterior_botao) {
        estado_sistema = !estado_sistema;
    }
    
    estado_anterior_botao = botao_atual;
    erro_detectado = ((sensA && !sensB) || (sensA && !sensC) || (sensB && !sensC) || (sensC && !sensD));
    // Verificação de Erros (A sua lógica de reg_niveis está correta, mas pode ser direta)
    if (erro_detectado) {
        desligar(Evs); 
        desligar(Eve);
        ligar(erro_flag);
        
    } else {
        
        desligar(erro_flag);
        
        if(estado_sistema){
            
            if (sensA){ // Nivel A (Último nível)
                desligar(Eve);
            } else { // Não
                ligar(Eve);
            }

            if (sensB || sensA){ // Nivel B ou A
                ligar(Evs);
            }
            
            else if (sensD && !sensC){ // Atingiu o Nível D, mas não o C
                desligar(Evs);
            }
        } else {
            desligar(Eve);
            
            if (!sensD) {  // sensor D desativa (reservatório vazio)
              desligar(Evs);
            }
        }    
    }
    return 0;
}




/* END Questao5 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
