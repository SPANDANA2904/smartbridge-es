/*
 * display_11_to_19.c
 *
 * Created: 6/10/2019 10:52:37 AM
 * Author : lenovo
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	while (1)
	{
		PORTD = 0xBF;
		_delay_ms(400);
		PORTD = 0x86;
		_delay_ms(400);
		PORTD = 0xDB;
		_delay_ms(400);
		PORTD = 0xCF;
		_delay_ms(400);
		PORTD = 0xE6;
		_delay_ms(400);
		PORTD = 0xED;
		_delay_ms(400);
		PORTD = 0xFD;
		_delay_ms(400);
		PORTD = 0x87;
		_delay_ms(400);
		PORTD = 0xFF;
		_delay_ms(400);
		PORTD = 0xE7;
		_delay_ms(400);
	}
}