#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "putchar.h"
#include "init.h"
#include "q.h"


int uart_putchar(char ch, FILE *stream)
{
   if (ch == '\n')
      uart_putchar('\r', stream);
   cli();
   if (!uart_busy) {
      UDR0 = ch;
	  uart_busy = 1;
   }
   else {
      while(q_insert(ch) == 0) {
	     sei();
		 _delay_ms(100);
		 cli();
      }
   }
   sei();
   return(1);
}
