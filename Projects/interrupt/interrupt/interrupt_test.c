/*
 * interrupt.c
 *
 * Created: 08-10-2020 13:50:20
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 1000000UL

int main(void)
{
	DDRC=0x08;
	PORTD|=1<<2;
	DDRA=0xff;
	
	MCUCR=0x02;
	GICR=0x40;
	sei();
    while(1)
	{
		PORTA=0xff;
		_delay_ms(1000);
		PORTA=0x00;
		_delay_ms(1000);
	}
}	
   ISR(INT0_vect)
   {
	   PORTC^=0x08;
   }
