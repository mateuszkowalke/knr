#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char c;
    int (*modfn)(int);
    printf("%s\n", argv[0]);
    if (strcmp(argv[0], "lower") == 0 || strcmp(argv[0], "./lower") == 0) {
        modfn = tolower;
    } else {
        modfn = toupper;
    }
    while ((c = getchar()) != EOF) {
        putchar(modfn(c));
    }
    return EXIT_SUCCESS;
}
