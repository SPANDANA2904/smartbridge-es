/*
 * timer.c
 *
 * Created: 6/10/2019 12:07:39 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#define LED PB0

int main(void)
{
    uint8_t timerOverflowCount=0;
	DDRB=0xFF; //configure PORTB as output
	TCNT0=0x00;
	TCCR0=(1<<CS00)|(1<<CS02);
    while (1) 
    {
		while((TIFR & 0x01)==0);
		TCNT0=0x00;
		TIFR=0x01;  //clear timer1 overflow flag
		timerOverflowCount++;
		if(timerOverflowCount>=10)
		{
			PORTB^=(0x01<<LED);
			timerOverflowCount=0;
		}
    }
}

