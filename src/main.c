/************* t.c file of C2.5 **************/
int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // data array
int sum;

#include <string.h>  // contains strlen(), strcmp(), etc.

#include "uart.h"  // UART driver code file

int cs122a_main() {
  int i;
  sum = 10;
  char string[64];
  UART* up;
  uart_init();  // initialize UARTs

  for (int i=0; i <4; i++)
  {
    UART *up = &uart[i];
    unsigned int divisor = *(up->base + UARTIBRD);
    unsigned int lcr = *(up->base + UARTLCR);
    unsigned int baud = 7380000 / (16 * divisor);

    uprintf(&uart[0], "UART[%d] Baudrate: %u\n", i, baud);
    uprintf(&uart[0], "UART[%d] Line Control Register: 0x%x\n", i, lcr);
  }
}