/*
 * blinking.c
 *
 * Created: 6/4/2019 12:36:51 PM
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
		PORTD = 0xFF;
		_delay_ms(220);
		PORTD = 0x00;
		_delay_ms(220);
    }
}

