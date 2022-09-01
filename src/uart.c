#include <types.h>

#define UART     0x10000000
#define UART_THR (u8*)(UART + 0x00)
#define UART_LSR (u8*)(UART + 0x05)
#define UART_LSR_IDLE_MASK 0x40

void uart_putc(char ch) {
  while ((*UART_LSR & UART_LSR_IDLE_MASK) == 0);
  *UART_THR = ch;
}

void uart_puts(char *str) {
  while (*str) uart_putc(*str++);
}
