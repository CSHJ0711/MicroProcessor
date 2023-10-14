#include <stdio.h>
#include "isprime.h"
#include "uart.h"

int main()
{
   int i;
   uart_init();
   for (i = 3; i <= 2000; i++) {
    if (is_prime(i)) printf("%d is a prime number !!!\n",i);
	else printf("%d is not a prime number !!!\n",i);
  }
  printf("The end!!!\n");
  while(1);
  return 0;
}


