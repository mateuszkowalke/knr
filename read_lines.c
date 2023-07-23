#include <stdio.h>

#define MAX_LINE_LEN 8

int get_line(char line[], int max_line);
void copy(char from[], char to[]);

int main() {
  char longest_line[MAX_LINE_LEN];
  int longest_len = 0;

  char curr_line[MAX_LINE_LEN];
  int curr_len;

  int last_empty = 0;
  while ((curr_len = get_line(curr_line, MAX_LINE_LEN)) >= 0 && !last_empty) {
    if (curr_len > longest_len) {
      longest_len = curr_len;
      copy(curr_line, longest_line);
      last_empty = 0;
    }

    if (curr_len == 0)
      last_empty = 1;
  }

  if (longest_len > 0) {
    printf("%s\n", longest_line);
    printf("%d\n", longest_len);
  }

  return 0;
}

int get_line(char line[], int max_line) {
  char c;
  int i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i == 0 && c == '\n')
      return 0;
    if (i < max_line - 1)
      line[i] = c;
    i++;
  }

  if (c == '\n' && i < max_line - 1) {
    line[i] = c;
    i++;
  }

  for (int j = i < max_line ? i : max_line - 1; j >= 0; j--) {
    if (line[j] == ' ' || line[j] == '\t')
      line[j] = '\0';
  }

  return i - 1;
}

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
