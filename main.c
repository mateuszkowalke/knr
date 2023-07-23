#include <limits.h>
#include <stdio.h>

int main() {
    short su = ~((short)1 << (sizeof(short) * 8) - 1);
    short sl = ((short)1 << (sizeof(short) * 8) - 1);
    printf("short: %d - %d / %ld bytes\n", sl, su, sizeof(short));
    int iu = ~(1 << (sizeof(int) * 8) - 1);
    int il = (1 << (sizeof(int) * 8) - 1);
    printf("int: %d - %d / %ld bytes\n", il, iu, sizeof(int));
    long lu = ~((long)1 << (sizeof(long) * 8) - 1);
    long ll = ((long)1 << (sizeof(long) * 8) - 1);
    printf("long: %ld - %ld / %ld bytes\n", ll, lu, sizeof(long));

    unsigned short usu = ~0;
    unsigned short usl = 0;
    printf("unsigned short: %d - %d / %ld bytes\n", usl, usu, sizeof(unsigned short));
    unsigned int uiu = ~0;
    unsigned int uil = 0;
    printf("unsigned int: %d - %u / %ld bytes\n", uil, uiu, sizeof(unsigned int));

    int f_rep = 0b10000000100000000000000000000000;
    float f = *(float *) &f_rep;
    printf("float: %f\n", f);
}
