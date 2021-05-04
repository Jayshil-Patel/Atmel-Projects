/*
 * led_test.cpp
 *
 * Created: 02-10-2020 19:42:54
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0xff;
    while(1)
	
    {
		PORTC=0xff;
		_delay_ms(100);
		PORTC=0x00;
		_delay_ms(100);
        //TODO:: Please write your application code 
    }
}