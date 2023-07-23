#include <stdio.h>

int pstrcmp(char *s, char *t) {
    while(*s && *t && *s++ == *t++);
    return *--t - *--s;
}

int main() {
    char *s = "string2";
    char *t = "string2";
    printf("Comparing:\n%s\nand\n%s\nresult: %d\n", s, t, pstrcmp(s, t));
}
