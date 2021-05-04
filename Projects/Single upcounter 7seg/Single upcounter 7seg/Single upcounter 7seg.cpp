/*
 * Single_upcounter_7seg.cpp
 *
 * Created: 03-09-2020 12:50:36
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <util/delay.h>
unsigned char seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x0d,0x7d,0x07,0x7f,0x6f};
	unsigned int j;
	int main(void)
{
	DDRD-0xff;
    while(1)
    {
        for (j=0;j<10;j++)
        {
			PORTD=seg[j];
			_delay_ms(1000);
			
        }
         
    }
	return 0;
}