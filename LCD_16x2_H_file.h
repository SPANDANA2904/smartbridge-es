#ifndef LCD_16x2_H_H

#define LCD_16x2_H_H

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>

#define enable 5
#define registerselection 7

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);

#endif
