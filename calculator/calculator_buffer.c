#include "calculator_buffer.h"
#include <stdio.h>

char pushback = '\0';

char getch() {
  if (pushback != '\0') {
    char res = pushback;
    pushback = '\0';
    return res;
  } else {
    return getchar();
  }
}

void ungetch(char c) {
  if (pushback != '\0') {
    printf("Pushback character already defined.");
  } else {
    pushback = c == EOF ? '\0' : c;
  }
}

void ungets(char *s) {
  int i = 0;
  while (s[i] != '\0') {
    ungetch(s[i++]);
  }
}
