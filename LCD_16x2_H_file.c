#include "LCD_16x2_H_file.h"

void send_a_character(unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<registerselection);
	PORTD|=(1<<enable);
	_delay_ms(50);
	PORTD&=~(1<<enable);
	PORTC=0;
}

void send_a_command(unsigned char command)
{
	PORTC=command;
	PORTD&=~(1<<registerselection);
	PORTD|=(1<<enable);
	_delay_ms(50);
	PORTD&=~(1<<enable);
	PORTC=0;
}

void send_a_string(char *string_of_characters)
{
	
	while(*string_of_characters>0)
	{
		send_a_character(*string_of_characters++);
	}
}


