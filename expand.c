#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// assumes target has enough space to fit expanded string
void expand(const char *src, char *target) {
  int i, j;
  i = j = 0;
  target[0] = src[0];
  for (i = 1, j = 1; i < strlen(src) - 1; i++) {
    if (src[i] == '-') {
      while (target[j-1] < src[i + 1]) {
        target[j++] = target[j - 1] + 1;
      }
      i++;
    } else {
      target[j++] = src[i];
    }
  }
  target[j] = src[i];
}

int main(int argc, char *argv[]) {
  char *src = "-adda-e0-3-53-";
  char *target = malloc(128);
  expand(src, target);
  printf("%s\n", target);
  return EXIT_SUCCESS;
}
