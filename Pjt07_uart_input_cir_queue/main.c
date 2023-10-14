#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "init.h"
#include "ISR_TX.h"
#include "ISR_RX.h"
#include "prime.h"
#include "putchar.h"
#include "q.h"

int main()
{
	char cmd[128], ch;
	int n = 0;
	uart_init();
	sei();
	printf("$ ");
	while(1) {
		cli();
		ch = qi_delete();
		sei();
		if(ch) { 
			if(ch == '\r') {
		//	if(ch == '\n') {
				cmd[n] = 0;
				int num = cmd[3] - '0';
				if(num >= 1 && num<=10) {
				if(!strncmp(cmd,"app",3)) {
					if(cmd[3] == '\0') {
						app_prime(2000);
					} else {
						app_prime(atoi(&cmd[3]) * 100);
					}
				}
				}
				n = 0;
				printf("$ ");
			}
			else 
				cmd[n++] = ch;
		}	
	}
	return 0;	
}
