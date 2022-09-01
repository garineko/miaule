#include <uart.h>
#include <stdlib.h>

void start_kernel(void) {
  uart_puts("Hello, world!\n");
  uart_puts("Hello, world!\n");
  i32 values[10] = {
    -2147483648,
    -2147483648,
    0,
    0,
    2147483647,
    2147483647,
    114,
    514,
    1919,
    810
  };
  i32 radices[10] = {
    10,
    16,
    10,
    16,
    10,
    16,
    10,
    10,
    10,
    10
  };
  char buffer[12];
  for (size_t i = 0; i < 10; i++) {
    uart_puts(i32toa(values[i], buffer, 12, radices[i]) != NULL ? buffer : "error");
    uart_putc('\n');
  }
  uart_puts("Hello, world!\n");
  uart_puts("Hello, world!\n");
  while (1);
}
