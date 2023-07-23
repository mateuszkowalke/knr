#include <stdio.h>
#include <stdlib.h>

void escape(char *s, char *t) {
  char c;
  int i, j;
  i = j = 0;
  while ((c = s[i++]) != '\0') {
    switch (c) {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    default:
      t[j++] = c;
      break;
    }
  }
}

void unescape(char *s, char *t) {
  char c;
  int i, j;
  i = j = 0;
  while ((c = s[i++]) != '\0') {
    switch (c) {
    case '\\':
      if ((c = s[i++]) == 'n') {
        t[j++] = '\n';
      } else {
        t[j++] = '\t';
      }
      break;
    default:
      t[j++] = c;
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  char *s = "Some text with\\nnewline.\\tAnd tab.";
  char t[100];
  unescape(s, t);
  printf("%s\n", t);
  return EXIT_SUCCESS;
}
