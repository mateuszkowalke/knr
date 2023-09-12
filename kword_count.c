#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define NKEYS sizeof(keytab) / sizeof(keytab[0])

struct key {
    char *word;
    int count;
};

struct key keytab[] = {
    {"auto", 0},     {"break", 0},    {"case", 0},     {"char", 0},
    {"const", 0},    {"continue", 0}, {"default", 0},  {"do", 0},
    {"double", 0},   {"else", 0},     {"enum", 0},     {"extern", 0},
    {"float", 0},    {"for", 0},      {"goto", 0},     {"if", 0},
    {"int", 0},      {"long", 0},     {"register", 0}, {"return", 0},
    {"short", 0},    {"signed", 0},   {"sizeof", 0},   {"static", 0},
    {"struct", 0},   {"switch", 0},   {"typedef", 0},  {"union", 0},
    {"unsigned", 0}, {"void", 0},     {"volatile", 0}, {"while", 0},
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main() {
    int n;
    char *word = malloc(sizeof(char) * MAXWORD);

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }

    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }

    return 0;
}

int binsearch(char *word, struct key *wordtab, int wordtablen) {
    int min = 0;
    int max = wordtablen - 1;
    int n, cmp;

    while (min <= max) {
        n = (max + min) / 2;
        if ((cmp = strcmp(word, wordtab[n].word)) < 0) {
            max = n - 1;
        } else if (cmp > 0) {
            min = n + 1;
        } else {
            return n;
        }
    }
    return -1;
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getchar()))
        ;

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalpha(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    }

    *w = '\0';
    return word[0];
}
