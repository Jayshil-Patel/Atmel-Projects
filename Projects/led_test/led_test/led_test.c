/*
 * led_test.c
 *
 * Created: 02-10-2020 18:44:18
 *  Author: Jay
 */ 

#include <avr/io.h>
#include <util/delay.h>

int function(void)
{
    DDRC=0xff;
	
while(1)
{
	PORTC=0xff;
	_delay_ms(100);
	PORTC=0x00;
	_delay_ms(100);
	
}	
    return 0;
}