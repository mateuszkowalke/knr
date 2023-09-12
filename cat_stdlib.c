#include <stdio.h>
#include <stdlib.h>

void filecp(FILE *f1, FILE *f2);

int main(int argc, char *argv[])
{
    if (argc == 1) {
        filecp(stdin, stdout);
        exit(0);
    }

    FILE *f;
    // for error handling
    char *prog = argv[0];

    while (--argc > 0) {
        if ((f = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "%s: error opening file %s\n", prog, *argv);
            exit(1);
        } else {
            filecp(f, stdout);
            fclose(f);
        }
    }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing to STDOUT\n", prog);
        exit(2);
    }

    exit(0);
}

void filecp(FILE *fsrc, FILE *fdst) {
    char c;
    while ((c = getc(fsrc)) != EOF) {
        putc(c, fdst);
    }
}
