#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: compare_files <file1> <file2>\n");
    }

    FILE *file1, *file2;
    if ((file1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
    }
    if ((file2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[2]);
    }

    char line1[MAXLINE], line2[MAXLINE];
    while (fgets(line1, MAXLINE, file1) != NULL) {
        fgets(line2, MAXLINE, file2);
        if (strcmp(line1, line2) != 0) {
            printf("%s\n%s\n", line1, line2);
            exit(0);
        }
    }

    return EXIT_SUCCESS;
}
