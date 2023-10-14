#include <avr/interrupt.h>
#include "init.h"
#include "isr.h"
#include "prime.h"
#include "putchar.h"
#include "q.h"

int main() {
   uart_init();
   sei();
   app_prime(2000);
   while(1);
   return 0;
}
