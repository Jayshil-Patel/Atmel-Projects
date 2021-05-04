/*
 * MCA_expt_5.c
 *
 * Created: 03-10-2020 21:00:50
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRA = DDRA | 0x01;
	TCCR0=0x05; //set the control register.
	TCNT0=252; //set counter value to 252.
	sei(); // enable global switch.
	TIMSK|=(1<<TOIE0); //set interrupt flag to 1.
	while(1)
	{
	}
	return 0;
}
void TIMER0_OVF_vect() //ISR of interrupt.
{
	TCNT0=252;
	PORTA^=(1<<PA0);
	sei();
}
