/*
 * DC_motor_button.c
 *
 * Created: 6/11/2019 10:49:02 AM
 * Author : lenovo
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	DDRD &= ~(1<<PD0);
	DDRA &= ~(1<<PA0);
	while(1)
	{
		if((PIND & (1<<PD0)) == 0)
		{
			PORTC=0x01;
			_delay_ms(5000);
			PORTC=0x00;
			_delay_ms(2000);
		}
		if((PINA & (1<<PA0)) == 0)
		{
			PORTC=0x02;
			_delay_ms(5000);
			PORTC=0x00;
			_delay_ms(2000);
		}
	}
}

