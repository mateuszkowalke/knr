#include <stdio.h>
#include <stdlib.h>

void shellsort(int v[], int n) {
  int gap, i, j, tmp;

  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        tmp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = tmp;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int v[] = {3, 4, 2, 5, 3, 4, 5, 2, 7, 4, 3, 5, 2};
  shellsort(v, 13);
  for (int i = 0; i < 13; i++) {
    printf("%d, ", v[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}
