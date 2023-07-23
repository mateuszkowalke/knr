#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pstrcat(char *s, char *t) {
    while (*s++ != '\0')
        ;
    s--;
    while ((*s++ = *t++) != '\0')
        ;
}

int main() {
    char *s = malloc(128);
    strcpy(s, "Poczatek ");
    char *t = "koniec.";
    pstrcat(s, t);
    printf("%s\n", s);
}
