/*
 * LCD.c
 *
 * Created: 6/7/2019 11:55:21 AM
 * Author : lenovo
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define RS 7//RS pin assigning to pin 7 PORTD
#define E 5//E pin assigning to pin 5 PORTD

void send_command(unsigned char command);
void send_character(unsigned char character);

int main(void)
{
   DDRC = 0xFF;//assigning PORTC as OUTPUT for Datapins
   DDRD = 0xFF;//assigning PORTD as OUTPUT for RS & E
   _delay_ms(50);
   send_command(0x01);//all clear command
   send_command(0x38);//16*2 line LCD
   send_command(0x0E);//screen and cursor on
   //data to print
   send_character(0x73);
   send_character(0x70);
   send_character(0x61);
   send_character(0x6E);
   send_character(0x64);
   send_character(0x61);
   send_character(0x6E);
   send_character(0x61);
   
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


