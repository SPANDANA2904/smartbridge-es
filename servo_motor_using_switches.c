/*
 * servo_motor_using_2_switches.c
 *
 * Created: 6/12/2019 10:37:04 AM
 * Author : lenovo
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	 
	 //configure TIMER1
	 TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11); //NON Inverted
	 TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=(fast PWM)
	 ICR1=4999; //fPWM=50Hz(PERIOD=20 ms standard)
	 DDRD|=(1<<PD5); //PWM pin5 as out
	 
	 DDRC &= ~(1<<PC0);
	 DDRA &= ~(1<<PA0);
	 
	while(1)
	{
		
		if((PINC & (1<<PC0)) == 0)
		{
			OCR1A=280; //90 degree
			_delay_ms(500);
		}
		if((PINA & (1<<PA0)) == 0)
		{
			OCR1A=535; //180 degree
			_delay_ms(500);
		}
	}
}

