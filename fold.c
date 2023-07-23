#include <stdio.h>

#define MAX_LINE_LEN 512
int N = 40;

int get_line(char line[], int max_line);
void copy(char from[], char to[]);
void reverse(char s[], int l);
void insert_newline(char s[], int l, int pos, int max_l);

int main() {
  char modified_line[MAX_LINE_LEN + MAX_LINE_LEN / N];
  char curr_line[MAX_LINE_LEN];
  int curr_len;
  while ((curr_len = get_line(curr_line, MAX_LINE_LEN)) > 0) {
    int last_blank = -1;
    char c = 0;
    for (int i = 0; i < curr_len; i++) {
      if ((c = curr_line[i]) == '\t' || c == ' ') {
        last_blank = i;
      }
      if (i > N && last_blank != -1) {
        modified_line[last_blank] = '\n';
        i = last_blank;
        last_blank = -1;
        N *= 2;
      } else {
        modified_line[i] = c;
      }
      modified_line[i + 1] = '\0';
    }
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

void insert_newline(char s[], int l, int pos, int max_l) {}
