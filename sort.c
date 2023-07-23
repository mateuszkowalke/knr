#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 4096
#define MAXLINE 200

char *lineptr[MAXLINES];

int readlines(char *lineptr[], size_t maxlines);
void writelines(char *lineptr[], size_t nlines);
void lqsort(char *lineptr[], size_t left, size_t right);
void generic_qsort(void *lineptr[], size_t left, size_t right, int (*comp)(void *, void*));
int numcmp(const char *, const char *);
int get_line(char *lineptr, size_t maxlen);
void swap(char *lines[], size_t i, size_t j);

int main(int argc, char *argv[]) {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) <= 0) {
        printf("Error: input too big to sort!");
        return EXIT_FAILURE;
    }
    int numeric = 0;
    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    /* lqsort(lineptr, 0, nlines - 1); */
    generic_qsort((void **)lineptr, 0, nlines, (int (*)(void *, void*))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return EXIT_SUCCESS;
}

int readlines(char *lineptr[], size_t maxlines) {
    int n = 0;
    int len;
    if ((*lineptr = malloc(sizeof(char) * MAXLINE)) == NULL)
        return -1;
    while ((len = get_line(*lineptr, MAXLINE)) > 0 && n++ < maxlines) {
        lineptr++;
        if ((*lineptr = malloc(sizeof(char) * MAXLINE)) == NULL)
            return -1;
    }
    return n;
}

void writelines(char *lineptr[], size_t nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void lqsort(char *lineptr[], size_t left, size_t right) {
    if (left >= right)
        return;
    size_t last;
    swap(lineptr, left, (left + right) / 2);
    last = left;
    for (size_t i = left + 1; i <= right; i++)
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, i, ++last);
    swap(lineptr, left, last);
    lqsort(lineptr, left, last - 1);
    lqsort(lineptr, last + 1, right);
}

int get_line(char *lineptr, size_t maxlen) {
    char c;
    size_t n = maxlen - 1;
    while ((c = getchar()) != '\n' && c != EOF && n-- > 0)
        *lineptr++ = c;
    *lineptr = '\0';
    return maxlen - n - 1;
}

void swap(char *lines[], size_t i, size_t j) {
    char *tmp = lines[i];
    lines[i] = lines[j];
    lines[j] = tmp;
}
