#include <stdio.h>
#include <avr/io.h>
#include <compat/deprecated.h>
#include "init.h"
#include "putchar.h"
#include "q.h"

FILE Mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
char uart_busy;

void uart_init()
{
   stdout = &Mystdout;
   uart_busy = 0;
   q_init();
   UBRR0H = 0x00; UBRR0L = 0x07; //115.2k
   sbi(UCSR0A, U2X0); //UCSR0A |= (1 << U2X0);
   sbi(UCSR0B, TXEN0);
   sbi(UCSR0B, TXCIE0);
}
