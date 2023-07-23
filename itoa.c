#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s) {
  char tmp;
  size_t len = strlen(s);
  for (int i = 0; i < len / 2; i++) {
    tmp = s[i];
    s[i] = s[len - i - 1];
    s[len - i - 1] = tmp;
  }
}

void itoa(int n, char *s) {
  int i, sign;
  uint m;
  if ((sign = n) < 0) {
    m = n == -(1 << (sizeof(int) * 8 - 1)) ? (uint)(1 << (sizeof(int) * 8 - 1))
                                           : -n;
  } else {
    m = n;
  }
  i = 0;
  do {
    s[i++] = m % 10 + '0';
  } while ((m /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void itob(int n, char *s, int b) {
  int i, sign;
  uint m;
  if ((sign = n) < 0) {
    m = n == -(1 << (sizeof(int) * 8 - 1)) ? (uint)(1 << (sizeof(int) * 8 - 1))
                                           : -n;
  } else {
    m = n;
  }
  i = 0;
  printf("m: %d\n", m);
  do {
    if (m % b > 9) {
      s[i++] = (m % b) % 10 + 'a';
    } else {
      s[i++] = m % b + '0';
    }
  } while ((m /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void itoa_pad(int n, char *s, int size) {
  int i, sign;
  uint m;
  if ((sign = n) < 0) {
    m = n == -(1 << (sizeof(int) * 8 - 1)) ? (uint)(1 << (sizeof(int) * 8 - 1))
                                           : -n;
  } else {
    m = n;
  }
  i = 0;
  do {
    s[i++] = m % 10 + '0';
  } while ((m /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  while (i < size) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

int itoa_recursive(int n, char *s, int i) {
  if (n < 0) {
    s[i++] = '-';
    n = -n;
  }

  if (n / 10) {
    i = itoa_recursive(n / 10, s, i);
  }

  s[i] = n % 10 + '0';

  return i + 1;
}

int main(int argc, char *argv[]) {
  char *s = malloc(128);
  int n = -255;
  itoa_recursive(n, s, 0);
  printf("%d\n", n);
  printf("%s\n", s);
  return EXIT_SUCCESS;
}
