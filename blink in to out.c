/*
 * blinking6.c
 *
 * Created: 6/4/2019 3:39:16 PM
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
		PORTD = 0x18;
		_delay_ms(220);
		PORTD = 0x24;
		_delay_ms(220);
		PORTD = 0x42;
		_delay_ms(220);
		PORTD = 0x81;
		_delay_ms(220);
	}
}




