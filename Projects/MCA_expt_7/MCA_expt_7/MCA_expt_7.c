/*
 * MCA_expt_7.c
 *
 * Created: 03-10-2020 21:11:03
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRC |= (1<<PC3); //set PC3 as output port.
	PORTD = (1<<PD2); //set PD2 as output port.
	MCUCR = 0x01; //set MCU control register.
	GICR = (1<<INT0); //set control register to external interrupt mode.
	sei();
	while(1);
}
ISR (INT0_vect)
{
	PORTC ^= (1<<PC3);
}
