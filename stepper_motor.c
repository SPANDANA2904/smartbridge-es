/*
 * stepper_motor.c
 *
 * Created: 6/12/2019 10:54:12 AM
 * Author : lenovo
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRA=0x0F; //make portA lower pins as output
	int period=2;
    while (1) 
    {
		//rotate clockwise
		for(int i=0;i<50;i++)
		{
			PORTA=0x09;
			_delay_ms(period);
			PORTA=0x08;
			_delay_ms(period);
			PORTA=0x0C;
			_delay_ms(period);
			PORTA=0x06;
			_delay_ms(period);
			PORTA=0x04;
			_delay_ms(period);
			PORTA=0x02;
			_delay_ms(period);
			PORTA=0x03;
			_delay_ms(period);
			PORTA=0x01;
			_delay_ms(period);
		}
		PORTA=0x09;
		_delay_ms(period);
		_delay_ms(1000);
		//rotate anti-clockwise
		for(int i=0;i<50;i++)
		{
			PORTA=0x01;
			_delay_ms(period);
			PORTA=0x03;
			_delay_ms(period);
			PORTA=0x02;
			_delay_ms(period);
			PORTA=0x04;
			_delay_ms(period);
			PORTA=0x06;
			_delay_ms(period);			
			PORTA=0x0C;
			_delay_ms(period);
			PORTA=0x08;
			_delay_ms(period);
			PORTA=0x09;
			_delay_ms(period);
		}
		PORTA=0x09;
		_delay_ms(period);
		_delay_ms(1000);
	}
}

