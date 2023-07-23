#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 2) {
        printf("usage: tail -n\n");
        return EXIT_FAILURE;
    }

    int n = 10;
    if (argc == 2 && (n = atoi(argv[1])) && n == 0) {
        printf("error: n has to be a valid integer value\n");
    }
    if (n < 0) n *= -1;

    char **buf = (char **)malloc(n * sizeof(char *));
    int bufidx = 0;

    size_t size;
    while (getline(&buf[bufidx], &size, stdin) > 0) {
        bufidx = (bufidx + 1) % n;
    }

    for (int i = n; i > 0; i--) {
        printf("%s", buf[bufidx]);
        bufidx = (bufidx + 1) % n;
    }
    return EXIT_SUCCESS;
}
