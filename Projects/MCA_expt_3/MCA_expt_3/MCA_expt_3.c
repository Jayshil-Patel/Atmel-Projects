/*
 * MCA_expt_3.c
 *
 * Created: 03-10-2020 19:57:50
 *  Author: Jay
 */ 


#include <avr/io.h>
int main(void)
{
	DDRA = 0XFF; //set PORTA as OUTPUT port.
	DDRB = DDRB & 0b11111100; //set PORTB pin PBO and PB1 as input port.
	unsigned char z;
	while(1)
	{
		z = PINB;
		z = z & 0b00000011; //masking last two bits of PORTB.
		switch(z)
		{
			case(0):
			PORTA = 0x55; //pattern1
			break;
			case(1):
			PORTA = 0xAA; //pattern2
			break;
			case(2):
			PORTA = 0xF0; //pattern3
			break;
			case(3):
			PORTA = 0x0F; //pattern4
			break;
		}
	}
	return 0;
}
