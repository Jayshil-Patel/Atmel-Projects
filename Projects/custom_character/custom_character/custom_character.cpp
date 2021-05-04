CODE:
#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
unsigned char font1[8]={0x0F,0x1E,0x1C,0x18,0x18,0x1C,0x1E,0x0F};
unsigned char font2[8]={0x0E,0x1F,0x1B,0x1F,0x1C,0x1F,0x1F,0x0E};
unsigned char word2[]={"WELCOME"};
int i;
char position; 
 
void lcd_data (char a,int b)       //LCD routine  for data and command
{   
PORTA=a;   
if(b==0)    
{      
PORTB&=~(1<<0);    
}   
else     
{      
PORTB|=(1<<0);           
}   
PORTB|=(1<<1);   
_delay_ms(2);   
PORTB&=~(1<<1);   
_delay_ms(2);  
} 
 
void lcd_init ()    
{     
   lcd_data(0x3C,0);       // 4-bit mode - 2 line - 5x10 font.      
   lcd_data(0x0C,0);       // Display cursor with blink.     
   lcd_data(0x06,0);       // Automatic Increment - No Display shift.        
   lcd_data(0x01,0);        
   lcd_data(0x02,0);       //Clear screen and return home                
}
 
int main()
{
     DDRA=0xff;
DDRB=0x03;
     lcd_init();
     lcd_data(0x40,0);
     for(i=0;i<=7;i++)
     {
       lcd_data(font1[i],1);
     }
     lcd_data(0x48,0);
     for(i=0;i<=7;i++)
     {
       lcd_data(font2[i],1);
     }
     lcd_data(0xc5,0);
     for(i=0;i<=6;i++)
     {
       lcd_data(word2[i],1);
     }
     i=0;
     position=0xC4;
     while(i<=6)                //Pac man eating out the letters animation sequence
     {
      lcd_data(position,0);      
      lcd_data(0x01,1);             //Displaying first pattern
      _delay_ms(150);
      lcd_data(position,0);
      lcd_data(0x00,1);           //Displaying second pattern with delay
      _delay_ms(300);
      lcd_data(position,0);
      lcd_data(' ',1);
      i++;
      position++;
     }
     lcd_data(0x01,1);
     return 0;
     while(1);
 
}