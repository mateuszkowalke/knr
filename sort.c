#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 4096
#define MAXLINE 200

char *lineptr[MAXLINES];

int readlines(char *lineptr[], size_t maxlines);
void writelines(char *lineptr[], size_t nlines);
void lqsort(char *lineptr[], size_t left, size_t right);
void generic_qsort(void *lineptr[], size_t left, size_t right,
                   int (*comp)(void *, void *), int reverse);
int numcmp(const char *, const char *);
int dircmp(const char *, const char *);
int get_line(char *lineptr, size_t maxlen);
void swap(void *lines[], size_t i, size_t j);

typedef struct flags_t {
    int numeric;
    int reverse;
    int fold;
    int dir;
} flags_t;

int main(int argc, char *argv[]) {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) <= 0) {
        printf("Error: input too big to sort!");
        return EXIT_FAILURE;
    }

    flags_t flags;
    flags.numeric = 0;
    flags.reverse = 0;
    flags.fold = 0;
    flags.dir = 0;

    if (argc > 1) {
        while (argc-- > 0) {
            if (strcmp(argv[argc], "-n") == 0) {
                flags.numeric = 1;
            } else if (strcmp(argv[argc], "-r") == 0) {
                flags.reverse = 1;
            } else if (strcmp(argv[argc], "-f") == 0) {
                flags.fold = 1;
            } else if (strcmp(argv[argc], "-d") == 0) {
                flags.dir = 1;
            }
        }
    }

    if (flags.fold) {
        for (int i = 0; i < nlines; i++) {
            for (int j = 0; j < strlen(lineptr[i]); j++) {
                lineptr[i][j] = tolower(lineptr[i][j]);
            }
        }
    }

    /* lqsort(lineptr, 0, nlines - 1); */
    int (*cmp_func)(void *, void *) =
        (int (*)(void *, void *))(flags.dir       ? dircmp
                                  : flags.numeric ? numcmp
                                                  : strcmp);
    generic_qsort((void **)lineptr, 0, nlines - 1, cmp_func, flags.reverse);
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
    swap((void *)lineptr, left, (left + right) / 2);
    last = left;
    for (size_t i = left + 1; i <= right; i++)
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap((void *)lineptr, i, ++last);
    swap((void *)lineptr, left, last);
    lqsort(lineptr, left, last - 1);
    lqsort(lineptr, last + 1, right);
}

void generic_qsort(void *els[], size_t left, size_t right,
                   int (*comp)(void *, void *), int reverse) {
    if (left >= right)
        return;
    size_t last;
    swap(els, left, (left + right) / 2);
    last = left;
    for (size_t i = left + 1; i <= right; i++) {
        int comp_res = comp(els[i], els[left]);
        if ((!reverse && comp_res < 0) || (reverse && comp_res))
            swap(els, i, ++last);
    }
    swap(els, left, last);
    generic_qsort(els, left, last - 1, comp, reverse);
    generic_qsort(els, last + 1, right, comp, reverse);
}

int get_line(char *lineptr, size_t maxlen) {
    char c;
    size_t n = maxlen - 1;
    while ((c = getchar()) != '\n' && c != EOF && n-- > 0)
        *lineptr++ = c;
    *lineptr = '\0';
    return maxlen - n - 1;
}

void swap(void *lines[], size_t i, size_t j) {
    void *tmp = lines[i];
    lines[i] = lines[j];
    lines[j] = tmp;
}

int numcmp(const char *a, const char *b) {
    double v1, v2;

    v1 = atof(a);
    v2 = atof(b);

    return v1 > v2 ? 1 : v1 < v2 ? -1 : 0;
}

int dircmp(const char *a, const char *b) {
    if (((*a < 65 || *a > 90) && (*a < 97 || *a > 122) &&
         (*a != ' ' || *a != '\t')) ||
        ((*b < 65 || *b > 90) && (*b < 97 || *b > 122) &&
         (*b != ' ' || *b != '\t')))
        return 0;

    return a > b ? 1 : a < b ? -1 : 0;
}
