/* 
 * File:   Macros.h
 * Author: bande
 *
 * Created on 10 de Novembro de 2026, 22:08
 */

#ifndef MACROS_H
#define	MACROS_H



#ifdef	__cplusplus
extern "C" {
#endif

#define getPin(name_pin_component) name_pin_component##_GetVal()

#define setPin(name_pin_component) name_pin_component##_SetVal()
#define clrPin(name_pin_component) name_pin_component##_ClrVal()
#define writePin(name_pin_component, valor) \
  ( (valor) ? (setPin(name_pin_component)) : (clrPin(name_pin_component)) )

#define getPort(name_port_component) name_port_component##_GetVal()    
#define writePort(name_port_component, valor) name_port_component##_PutVal(valor)

typedef signed char i8;
typedef signed int i16;
typedef unsigned char u8;
typedef unsigned int u16;

#ifdef	__cplusplus
}
#endif

#endif	/* MACROS_H */


