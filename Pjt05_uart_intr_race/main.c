#include <avr/interrupt.h>
#include "uart.h"
#include "ISR.h"

int main()
{
   int i;
   uart_init();
   sei();
   for ( i = 0; i < 10; i++) {
      uart_putstart("I Love you.\n" );
      uart_putstart("You love me.\n");
      uart_putstart("He loves her.\n");
   }
   uart_putstart( "End !!!\n");
   while(1);
      return 0;
}
