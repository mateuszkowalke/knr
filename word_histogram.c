#include <stdio.h>
#include <stdlib.h>

#define IN_WORD 1
#define OUT_WORD 0

#define WC 10

int main(int argc, char **argv) {
  int c, wl_len, nc, state;
  int *wl = malloc(sizeof(int) * WC);

  for (int i = 0; i < WC; i++) {
    wl[i] = 0;
  }
  wl_len = WC;
  nc = 0;

  state = OUT_WORD;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN_WORD) {
        if (nc >= wl_len) {
          wl = realloc(wl, sizeof(int) * nc);
          for (int i = wl_len; i < nc; i++) {
            wl[i] = 0;
          }
          wl_len = nc;
        }
        // this compensates for zero indexing - arr[0] stores the number of
        // words of length 1
        wl[nc - 1]++;
      }
      state = OUT_WORD;
      nc = 0;
    } else if (state == OUT_WORD) {
      state = IN_WORD;
      nc = 1;
    } else if (state == IN_WORD) {
      nc++;
    }
  }

  int max_occurences = 0;
  for (int i = 0; i < wl_len; i++) {
    if (wl[i] > max_occurences)
      max_occurences = wl[i];
  }

  putchar('\n');
  for (int i = max_occurences; i > 0; i--) {
    putchar(i + '0');
    putchar(' ');
    for (int j = 0; j < wl_len; j++) {
      if (wl[j] >= i) {
        putchar('#');
      } else {
        putchar(' ');
      }
    }
    putchar('\n');
  }

  return 0;
}
