#include "isprime.h"

int is_prime(int n) {
  int i;
  for ( i = 2; i <= n/2; i++)
    if ((n % i) == 0) return(0); //FALSE
  return(1); //true
}
