/*
 * bluetooth.c
 *
 * Created: 6/13/2019 11:14:53 AM
 * Author : lenovo
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED PORTB
char buffer[10];

void USARTInit(uint16_t ubrr_value)
{
	//set baud rate
	UBRRL = ubrr_value;
	UBRRH = (ubrr_value>>8);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	//enable receiver transmitter
	UCSRB=(1<<RXEN)|(1<<TXEN);
}

char USARTReadChar()
{
	//wait until data is available
	while(!(UCSRA & (1<<RXC)))
	{
		//do nothing
	}
	return UDR;
}

void USARTWriteChar(char data)
{
	while(!(UCSRA & (1<<UDRE)))
	{
		//do nothing
	}
	UDR=data;
}

int main()
{
   USARTInit(77);
   DDRB=0xFF; //output port
   char data;
   LED=0;
    while (1) 
    {
		data=USARTReadChar();
		if(data=='1')
		{
			LED |= 0xFF; //turn on LED
			//USART_SendString("LED_ON"); //send status of LED
		}
		else if(data=='2')
		{
			LED=0x00; //turn off LED
			//USART_SendString("LED_OFF"); //send status of LED
		}
		//else
		//USART_SendString("select proper option"); //send message
		
    }
	return 0;
}

