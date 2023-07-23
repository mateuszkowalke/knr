#include <stdio.h>
#include <stdlib.h>

int binsearch(int t, int arr[], size_t len) {
  int mid, low = 0, high = len - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] < t) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  printf("arr[mid]: %d\tmid: %d\n", arr[mid], mid);
  return arr[mid] == t ? mid : -1;
}

int binsearch2(int t, int arr[], size_t len) {
  int mid, low = 0, high = len - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] < t) {
      low = mid + 1;
    } else if (arr[mid] > t) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  int len = 2000000000;
  int *arr = malloc(sizeof(int) * len);
  for (int i = 0; i < len; i++) {
    arr[i] = i;
  }

  int res = binsearch(7, arr, len);
  printf("res: %d\n", res);
  return EXIT_SUCCESS;
}
