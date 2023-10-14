#include <avr/interrupt.h>
#include "ISR_TX.h"
#include "q.h"
#include "init.h"

ISR(USART0_TX_vect)
{
   char ch;

   if ((ch = qo_delete()) == 0)
      uart_busy = 0;
   else
      UDR0 = ch;
}
