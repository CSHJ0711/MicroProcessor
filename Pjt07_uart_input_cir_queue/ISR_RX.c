#include <avr/interrupt.h>
#include "ISR_RX.h"
#include "q.h"

ISR(USART0_RX_vect)
{
   char ch;

   ch = UDR0;
   qi_insert(ch);
}
