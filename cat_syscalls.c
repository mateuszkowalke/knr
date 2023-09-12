#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 4096

int filecp(int f1, int f2);

int main(int argc, char *argv[]) {
    // for error handling
    char *prog = argv[0];
    int cp_err;
    if (argc == 1) {
        if ((cp_err = filecp(0, 1)) < 0) {
            fprintf(stderr, "%s: error copying from stdin to stdout: %i\n",
                    prog, cp_err);
            exit(1);
        }
        exit(0);
    }

    int f;

    while (--argc > 0) {
        if ((f = open(*++argv, O_RDONLY, 0)) == -1) {
            fprintf(stderr, "%s: error opening file %s\n", prog, *argv);
            exit(1);
        } else {
            if ((cp_err = filecp(f, 1)) < 0) {
                fprintf(stderr, "%s: error copying from %s: %i\n", prog, *argv,
                        cp_err);
                exit(1);
            }
            close(f);
        }
    }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing to STDOUT\n", prog);
        exit(2);
    }

    exit(0);
}

int filecp(int fsrc, int fdst) {
    static char buf[BUFSIZE];
    int n;
    while ((n = read(fsrc, buf, BUFSIZE)) > 0) {
        if (write(fdst, buf, n) != n) {
            return -1;
        }
    }
    return n;
}
