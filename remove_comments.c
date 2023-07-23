#include <stdio.h>

int main() {
  char c;
  char inString = 0;
  while ((c = getchar()) > 0) {
    if (c == '"') {
      inString = !inString;
    }
    if (!inString) {
      if (c == '/') {
        char nextChar = getchar();
        if (nextChar == '/') {
          while ((c = getchar()) != '\n') {
          }
        } else if (nextChar == '*') {
          while (c != '*' || nextChar != '/') {
            c = nextChar;
            nextChar = getchar();
          }
        } else {
          putchar(c);
        }
      }
    }
    putchar(c);
  }

  return 0;
}
