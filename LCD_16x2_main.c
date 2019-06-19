/*
 * including_lib.c
 *
 * Created: 6/14/2019 9:56:22 AM
 * Author : lenovo
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#include "LCD_16x2_H_file.h"

int main(void)
{
	DDRC=0xFF;
	DDRA=0x00;
	DDRD=0xFF;
	_delay_ms(50);

	//voltage selection
	ADMUX|=(1<<REFS0)|(1<<REFS1);

	//prescale selection
	ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<ADPS1)|(1<<ADPS2);

	int16_t COUNTA=0;
	char SHOWA[3];
	send_a_command(0x01);
	_delay_ms(50);
	send_a_command(0x38);
	_delay_ms(50);
	send_a_command(0b00001111);
	_delay_ms(50);
	ADCSRA |= (1<<ADSC);

	while(1)
	{
		
		COUNTA=ADC/4;
		send_a_string("Smartbridge");
		send_a_command(0x80+0x40+0);
		send_a_string("Temp(C)=");
		send_a_command(0x80+0x40+8);
		
		//command for putting variable number in LCD
		itoa(COUNTA,SHOWA,10);
		
		send_a_string(SHOWA);
		send_a_string(" ");
		send_a_command(0x80+0);
	}
}

