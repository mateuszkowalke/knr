#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "alloc.h"

int main(int argc, char *argv[])
{
    printf("Allocating 20 bytes\n");
    char *s = alloc(20);
    printf("Storing string 'hello there' in allocated memory\n");
    strncpy(s, "hello there", 12);
    printf("Printing stored string: %s\n", s);
    printf("Freeing allocated memory\n");
    afree(s);
    return EXIT_SUCCESS;
}
