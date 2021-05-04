/*
 * MCA_lab_expt_1.c
 *
 * Created: 03-10-2020 19:20:34
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define leds PORTD

int main(void)
{
	DDRD=0xff;
    while(1)
    {
         leds=0xff;
		 _delay_ms(500);
		 leds=0x00;
		 _delay_ms(500);
    }
}