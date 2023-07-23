#include <stdio.h>

#define MAX_LINE_LEN 32
#define TAB_STOP 4

int get_line(char line[], int max_line);
void copy(char from[], char to[]);
void reverse(char s[], int l);

int main() {
  char modified_line[MAX_LINE_LEN * TAB_STOP];
  int modified_len;
  char curr_line[MAX_LINE_LEN];
  int curr_len;
  while ((curr_len = get_line(curr_line, MAX_LINE_LEN)) > 0) {
    int mod_i = 0;
    char c = 0;
    for (int i = 0; i < curr_len; i++) {
      if ((c = curr_line[i]) == '\t') {
        while (TAB_STOP - mod_i % TAB_STOP != 1) {
          modified_line[mod_i] = ' ';
          mod_i++;
        }
        modified_line[mod_i] = ' ';
        mod_i++;
      } else {
        modified_line[mod_i] = c;
        mod_i++;
      }
    }
    modified_line[mod_i] = '\0';
    printf("%s\n", modified_line);
  }

  return 0;
}

void reverse(char s[], int l) {
  char tmp;
  for (int i = 0; i < (l - 1) / 2; i++) {
    tmp = s[i];
    s[i] = s[l - 1 - i];
    s[l - 1 - i] = tmp;
  }
}

// returns length of read line ('\0' excluded from length)
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

  return i - 1;
}

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
