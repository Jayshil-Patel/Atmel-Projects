/*
 * MCA_expt_6.c
 *
 * Created: 03-10-2020 21:04:28
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRB |= (1<<PB1); //set PB1 as output port.
	OCR2 = 42; //set counter value to 42.
	sei(); // set global switch of interrupt as 1.
	TIMSK |= (1<<OCIE2); //set interrupt flag as 1.
	TCCR2 = 0x1B; //set control register in CTCmode.
	while (1);
}
void TIMER2_COMP_vect()
{
	PORTB ^= (1<<PB1);
	sei();
}
