#include "./calculator/calculator_buffer.h"
#include <ctype.h>
#include <stdio.h>

int getfloat(double *pn) {
    int c;
    double sign;

    // skip whitespace
    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1.0 : 1.0;

    if (c == '-' || c == '+')
        c = getch();

    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    if (c == '.') {
        c = getch();
        double divisor = 10.0;
        while (isdigit(c)) {
            *pn += (c - '0') / divisor;
            divisor *= 10.0;
            c = getch();
        }
    }

    *pn *= sign;

    if (c == EOF)
        ungetch(c);

    return c;
}

int main() {
    int ret;
    double res;
    ret = getfloat(&res);
    printf("ret: %d\n", ret);
    printf("res: %f\n", res);
}
