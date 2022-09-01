#include <stdlib.h>

void swap_char(char *x, char *y) {
  char t = *x;
  *x = *y;
  *y = t;
}

char *reverse_char(char *first, char *last) {
  char *buffer = first;
  last--;
  while (first < last) swap_char(first++, last--);
  return buffer;
}

i32 abs_i32(i32 x) {
  return x < 0 ? -x : x;
}

char *i32toa(i32 value, char *buffer, size_t size, i32 radix) {
  if (radix < 2 || radix > 32) return buffer = NULL;
  u32 n = (u32)abs_i32(value);
  size_t i = 0;
  while (n) {
    if (i == size) return buffer = NULL;
    int r = n % radix;
    buffer[i++] = r >= 10 ? r + 55 : r + 48;
    n /= radix;
  }
  if (i == size) return buffer = NULL;
  if (i == 0) buffer[i++] = '0';
  if (i == size) return buffer = NULL;
  if (value < 0 && radix == 10) buffer[i++] = '-';
  if (i == size) return buffer = NULL;
  buffer[i] = '\0';
  return reverse_char(buffer, buffer + i);
}
