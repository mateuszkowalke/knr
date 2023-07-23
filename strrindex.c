#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strrindex(char *s, char t) {
  for (int i = strlen(s); i >= 0; i--) {
    if (s[i] == t) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int res = strrindex(argv[1], argv[2][0]);
  printf("%c is in position %d in word %s\n", argv[2][0], res, argv[1]);
  return EXIT_SUCCESS;
}
