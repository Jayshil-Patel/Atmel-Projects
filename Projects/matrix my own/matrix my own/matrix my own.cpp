/*
 * matrix_my_own.cpp
 *
 * Created: 04-08-2020 20:04:18
 *  Author: Jay
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>

int main(void)
{
	int R[]={0XFE,0X09,0X09,0X09,0X09,0XFE};
	int C[]={0XFD,0XFB,0XF7,0XEF,0XDF,0XBF}; 
		
    while(1)
    {
        //TODO:: Please write your application code 
		DDRA=0xff;
		DDRB=0xff;
	for(int i=0;i<6;i++)	
		{
			PORTB=C[i];PORTA=R[i];
		
		_delay_ms(1);}
					
		
		
    }
}