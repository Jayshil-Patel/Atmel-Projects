/*
 * _2digit_counter_7seg.cpp
 *
 * Created: 03-09-2020 13:11:38
 *  Author: Jay
 */ 


#include <avr/io.h>
#include<util/delay.h>
unsigned char seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	static int i=0,j=0;
	unsigned char k,z,start_for=0,start_rev=99;

int main(void)
{
	DDRB=0xff;
	DDRC|=0x03;
	DDRA&=0x03;
	PORTA=0x03;
    while (1)
    {
		startup:
		if((PINA & 0x03)==2)
		{
			while((PINA & 0x03)==2)
			{
			for (i=start_for;i<100;i++)
			{
			for (j=0;j<50;j++)
			{
				PORTC=0x01;
				PORTB=seg[i/10];
				_delay_ms(10);
				PORTC=0x02;
				PORTB=seg[i%10];
				_delay_ms(10);
				if ((PINA & 0x03)!=2)
				{
					start_for=i;
					start_rev=1;
					goto startup;
				}
			}
			}
			start_for=0;
			}			
		}
		if((PINA & 0x03)==1)
		{
			while((PINA & 0x03)==1)
			{
				for (i=start_rev;i>-1;i--)
				{
					for (j=0;j<50;j++)
					{
						PORTC=0x01;
						PORTB=seg[i/10];
						_delay_ms(10);
						PORTC=0x02;
						PORTB=seg[i%10];
						_delay_ms(10);
						if ((PINA & 0x03)!=1)
						{
							start_for=i;
							start_rev=1;
							goto startup;
						}
					}
				}
				
			}
			start_rev=99;
		}
		
    }
	return 0;
	
}