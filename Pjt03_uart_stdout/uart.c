#include <stdio.h>
#include <avr/io.h>
#include <compat/deprecated.h>
#include <util/delay.h>
#include "uart.h"

int uart_putchar_1(char ch, FILE *stream);

FILE Mystdout = FDEV_SETUP_STREAM(uart_putchar_1, NULL, _FDEV_SETUP_WRITE);

void uart_init()
{
   stdout = &Mystdout;

   UBRR0H = 0x00; UBRR0L = 0x07; //115.2
   sbi(UCSR0A, U2X0); //115.2
   sbi(UCSR0B, TXEN0); //TX enable
}


int uart_putchar_1(char ch, FILE *stream)
{
  if (ch == '\n' )
    uart_putchar_1( '\r', stream );
   _delay_ms(100);
   UDR0 = ch;
   return(1);
}
