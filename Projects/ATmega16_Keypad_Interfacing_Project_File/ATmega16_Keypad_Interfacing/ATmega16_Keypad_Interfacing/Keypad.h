/*
 * Keypad.h
 *
 * Created: 21/10/2016 11:19:59 AM
 *  Author: amrut
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define KEY_PRT 	PORTA
#define KEY_DDR		DDRA
#define KEY_PIN		PINA


char keyfind();




#endif /* KEYPAD_H_ */