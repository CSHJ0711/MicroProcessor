#include <avr/interrupt.h>
#include "isr.h"
#include "q.h"
#include "init.h"

ISR(USART0_TX_vect)
{
   char ch;

   if ((ch = q_delete()) == 0)
      uart_busy = 0;
   else
      UDR0 = ch;
}
