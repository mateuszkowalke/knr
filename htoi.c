#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  if (NULL == argv[1]) {
    printf("Usage ./a.out <hexadecimal number>\n");
    return EXIT_FAILURE;
  }

  char *hex = argv[1];
  u_int64_t n = 0;
  for (int i = 0; i < strlen(hex); i++) {
    char c = hex[i];
    if (i == 0 && c == '0') {
      continue;
    }
    if (i == 1 && tolower(c) == 'x') {
      continue;
    }
    if (isdigit(c)) {
      n = n * 16 + (c - '0');
    } else if (isalpha(c = tolower(c)) && c <= 'h') {
      n = n * 16 + (c - 'a' + 10);
    } else {
      printf("Usage ./a.out <hexadecimal number>\n");
      return EXIT_FAILURE;
    }
  }

  printf("%s\t->\t%ld\n", hex, n);
  return EXIT_SUCCESS;
}
