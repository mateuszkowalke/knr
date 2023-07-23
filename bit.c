#include <stdio.h>
#include <stdlib.h>

void print_bit_value(uint n) {
  for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
    printf("%u", (n & 1 << i) > 0);
  }
  printf("\n");
}

uint setbits(uint x, int p, int n, uint y) {
  uint mask = ~(~0 << n) << (p + 1 - n);
  y = y & mask;
  x = x & ~mask;
  return x | y;
}

uint invert(uint x, int p, int n) {
  uint mask = ~(~0 << n) << (p + 1 - n);
  return x ^ mask;
}

uint rightrot(uint x, int n) {
  for (int i = 0; i < n; i++) {
    uint tmp = 1 & x;
    x = x >> 1;
    x = x | (1 << (sizeof(x) * 8 - 1)) & (tmp << (sizeof(x) * 8 - 1));
  }
  return x;
}

int main(int argc, char **argv) {
  uint x = 1234;
  print_bit_value(x);
  uint y = 4927;
  print_bit_value(y);
  x = setbits(x, 7, 4, y);
  print_bit_value(x);
  x = 1234;
  print_bit_value(x);
  x = invert(x, 7, 4);
  print_bit_value(x);
  printf("--------------\n");
  x = 1234;
  print_bit_value(x);
  x = rightrot(x, 8);
  print_bit_value(x);
  return EXIT_SUCCESS;
}
