#include "./calculator/calculator_buffer.h"
#include <ctype.h>
#include <stdio.h>

int getint(int *pn) {
    int c, sign;

    // skip whitespace
    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1 : 1;

    if (c == '-' || c == '+')
        c = getch();

    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign;

    if (c == EOF)
        ungetch(c);

    return c;
}

int main() {
    int res, ret;
    ret = getint(&res);
    printf("ret: %d\n", ret);
    printf("res: %d\n", res);
}
