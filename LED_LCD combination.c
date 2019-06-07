/*
 * LED_LCD.c
 *
 * Created: 6/7/2019 12:43:44 PM
 * Author : lenovo
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define RS 7//RS pin assigning to pin 7 PORTD
#define E 5//E pin assigning to pin 5 PORTD

void send_command(unsigned char command);
void send_character(unsigned char character);

int main(void)
{
	 DDRC = 0xFF;//assigning PORTC as OUTPUT for datapins
	 DDRD = 0xFF;//assigning PORTD as OUTPUT for RS & E
	 _delay_ms(50);
	 send_command(0x01);//all clear command
	 send_command(0x38);//16*2 line LCD
	 send_command(0x0E);//screen and cursor on
	DDRA |= (1<<PA0);
	DDRB &= ~(1<<PB0);
	while(1)
	{
		if((PINB & (1<<PB0)) == 0)
		{
			PORTA |= (1<<PA0);
			send_character(0x6F);
			send_character(0x6E);
			_delay_ms(1000);
			send_command(0x01);//all clear command
			PORTA &=~(1<<PA0);
			send_character(0x6F);
			send_character(0x66);
			send_character(0x66);
			_delay_ms(300);
			send_command(0x01);//all clear command
		}
	}
}

void send_command(unsigned char command)
{
	PORTC=command;
	PORTD&=~(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
}

void send_character(unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&=~(1<<E);
	PORTC=0;
}
