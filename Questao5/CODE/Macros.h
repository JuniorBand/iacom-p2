/* 
 * File:   Macros.h
 * Author: bande
 *
 * Created on 10 de Novembro de 2026, 22:08
 */

#ifndef MACROS_H
#define	MACROS_H

//#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

// name_pin_component_GetVal()
#define P(name_pin_component) name_pin_component##_GetVal()
   
//#define P(N, X) PORT##N##bits.R##N##X // P(A, 1) = PORTAbits.RA1

//typedef int8_t i8;
//typedef int16_t i16;
//typedef uint8_t u8;
//typedef uint16_t u16;

typedef short i8;
typedef int i16;
typedef unsigned short u8;
typedef unsigned int u16;

#ifdef	__cplusplus
}
#endif

#endif	/* MACROS_H */


