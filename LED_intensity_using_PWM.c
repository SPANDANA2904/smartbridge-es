/*
 * PMW_output.c
 *
 * Created: 6/10/2019 2:03:13 PM
 * Author : lenovo
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void PWM_init()
{
	//set fast PWM with non-inverted output
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB|=(1<<PB3); //set 0C0 pin as output
}

int main()
{
	unsigned char duty;
	PWM_init();
    while (1) 
    {
		for(duty=0;duty<255;duty++)
		{
			OCR0=duty; //increase LED intensity
			_delay_ms(8);
		}
		for(duty=255;duty>1;duty--)
		{
			OCR0=duty; //decrease LED intensity
			_delay_ms(15);
		}
    }
}

