#include <stdio.h>
#define swap(t, x, y) ({\
        t tmp = x;\
        x = y;\
        y = tmp;\
        })

int main(int argc, char *argv[])
{
    int x = 4;
    int y = 10;
    printf("x: %d, y: %d\n", x, y);
    swap(int, x, y);
    printf("x: %d, y: %d\n", x, y);
}
