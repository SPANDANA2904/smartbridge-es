/*
 * DC_motor.c
 *
 * Created: 6/11/2019 10:07:37 AM
 * Author : lenovo
 */ 


#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
    DDRD=0xFF;
    while (1) 
    {
		PORTD=0x01;
		_delay_ms(5000);
		PORTD=0x00;
		_delay_ms(4000);
		PORTD=0x02;
		_delay_ms(5000);
		PORTD=0x00;
		_delay_ms(4000);
	 }
}

