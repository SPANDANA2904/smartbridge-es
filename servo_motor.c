/*
 * servo_motor.c
 *
 * Created: 6/12/2019 10:05:20 AM
 * Author : lenovo
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    //configure TIMER1
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11); //NON Inverted
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=(fast PWM)
	ICR1=4999; //fPWM=50Hz(PERIOD=20 ms standard)
	DDRD|=(1<<PD5); //PWM pin5 as out
    while (1) 
    {
		OCR1A=97; //0 degree
		_delay_ms(500);
		
		OCR1A=280; //90 degree
		_delay_ms(500);
		
		OCR1A=535; //180 degree
		_delay_ms(500);
    }
}

