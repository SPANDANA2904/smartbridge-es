/*
 * IR_sensor.c
 *
 * Created: 6/11/2019 2:19:04 PM
 * Author : lenovo
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>

#define LED_OUTPUT PORTB
#define PIR_Input PINC

int main(void)
{
	DDRC=0x00; //input port
	DDRB=0xFF; //output port
	while(1)
	{
		LED_OUTPUT=PIR_Input; //when sensor detected LED will be high
	}
}




