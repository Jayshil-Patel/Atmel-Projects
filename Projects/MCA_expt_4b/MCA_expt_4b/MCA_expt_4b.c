/*
 * MCA_expt_4b.c
 *
 * Created: 03-10-2020 20:50:13
 *  Author: Jay
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
int main(void)
{
	DDRB=0xff;
	DDRA=0xff;
	DDRC=0x00;
	DDRD=0xff;
char a[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90}; //hex values for CC
int j,k,i;
int x=0,y=0,p=0;
unsigned int z;
PORTC=0xff;
PORTD=0xff;
while (1)
{
	jmp3:
	z=PINC;
	if(z==0xfe)
	{
		goto jmp1;
	}
	else if(z==0xff)
	{
		goto jmp2;
	}
	else
	{
		goto jmp3;
	}
	jmp1:
	for(j=y;j<=9999;j++)
	{
		for(i=0;i<=10;i++)
		{
			PORTA=0x01;
			PORTB=a[j/1000];
			_delay_ms(1);

			PORTA=0x00;
			PORTA=0x02;
			PORTB=a[(j/100)%10];
			_delay_ms(1);

			PORTA=0x00;
			PORTA=0x04;
			PORTB=a[(j%100)/10];
			_delay_ms(1);

			PORTA=0x00;
			PORTA=0x08;
			PORTB=a[j%10];
			_delay_ms(1);
			PORTA=0x00;
			if(PINC==0xff)
			{
				x=j;
				goto jmp2;
			}
		}
	}
	if(p==1)
	{
		x=99,y=0;
	}
	goto jmp3;
	jmp2:
	for(k=0;k<=5000;k++)
	{
		for(i=0;i<=500;i++)
		{
			PORTA=0x01;
			PORTB=a[x/1000];
			_delay_ms(1);

			PORTA=0x00;
			PORTA=0x02;
			PORTB=a[(x/100)%10];
			_delay_ms(1);

			PORTA=0x00;
			PORTA=0x04;
			PORTB=a[(x%100)/10];
			_delay_ms(1);

			PORTA=0x00;
			PORTA=0x08;
			PORTB=a[x%10];
			_delay_ms(1);

			PORTA=0x00;
			if(PINC==0xfe)
			{
				y=x;
				p++;
				goto jmp3;
			}
		}
	}
	goto jmp3;
}
return 0;
}
