/*
 * relay_module.c
 *
 * Created: 6/11/2019 3:43:07 PM
 * Author : lenovo
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0xFF;
	while(1)
	{
		PORTC=0xFF;
		_delay_ms(5000);
		PORTC=0x00;
		_delay_ms(2000);
	}
}






