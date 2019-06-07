/*
 * led_scrolling.c
 *
 * Created: 6/7/2019 2:39:10 PM
 * Author : lenovo
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0xFF;
	//DDRC |= (1<<PC0);
	DDRD &= ~(1<<PD0);
	while(1)
	{
		if((PIND & (1<<PD0)) == 0)
		{
			PORTA = 0x01;
			_delay_ms(220);
			PORTA = 0x02;
			_delay_ms(220);
			PORTA = 0x04;
			_delay_ms(220);
			PORTA = 0x08;
			_delay_ms(220);
			PORTA = 0x10;
			_delay_ms(220);
			PORTA = 0x20;
			_delay_ms(220);
			PORTA = 0x40;
			_delay_ms(220);
			PORTA = 0x80;
			_delay_ms(220);
		}
	}
}


