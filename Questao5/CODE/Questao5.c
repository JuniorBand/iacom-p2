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
#include "Botao_I.h"
#include "Nivel_A.h"
#include "Nivel_B.h"
#include "Nivel_C.h"
#include "Nivel_D.h"
#include "Evs.h"
#include "Eve.h"
#include "Flag_Erro.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Macros.h"


#define ligar(pino)    writePin(pino, 1)
#define desligar(pino) writePin(pino, 0)
    
static u8 botao_atual = 0;
static u8 sensA = 0;
static u8 sensB = 0;
static u8 sensC = 0;
static u8 sensD = 0;

volatile u8 erro_detectado = 0;
volatile u8 time_flag = 0;
volatile u8 estado_sistema = 0;
volatile u8 estado_anterior_botao = 0;

void verificar_niveis(void);


void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

  while (1){
  
    verificar_niveis();
  
  }

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/




void verificar_niveis(void){
    
    botao_atual = !getPin(Botao_I);
	  sensA = !getPin(Nivel_A);
    sensB = !getPin(Nivel_B);
    sensC = !getPin(Nivel_C);
    sensD = !getPin(Nivel_D);
    
    // Botao apertado e antes não apertado -> entra
    if (botao_atual && !estado_anterior_botao) {
        estado_sistema = !estado_sistema;
    }
    
    estado_anterior_botao = botao_atual;
    erro_detectado = ((sensA && !sensB) || (sensA && !sensC) || (sensB && !sensC) || (sensC && !sensD));
    // Verificação de Erros
    if (erro_detectado) {
        desligar(Evs); 
        desligar(Eve);
        ligar(Flag_Erro);
        
    } else {
        
        desligar(Flag_Erro);
        
        if(estado_sistema){
            
            if (sensA){ // Nivel A (Último nível)
                desligar(Eve);
            } else { // Não
                ligar(Eve);
            }

            if (sensC || sensB || sensA){ // Nivel B ou A
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
    return;
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
