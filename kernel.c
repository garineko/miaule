extern void uart_puts(char *str);

void start_kernel(void) {
  uart_puts("Hello, world!\n");
  while (1);
}
