#include <avr/interrupt.h>
#include "uart.h"
#include "ISR.h"

ISR(USART0_TX_vect)
{
   char ch = buf[bufi];
   if(!ch) 
   {
      bufi = buf[0] = 0, txend = 1; 
	  return;
   }
   if (ch == '\n' ) 
     buf[bufi] = '\r';
   else 
     bufi++;
   UDR0 = ch;
}
