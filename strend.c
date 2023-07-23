#include <stdio.h>
int strend(char *s, char *t) {
    char *send = s;
    char *tend = t;
    while (*send++ != '\0')
        ;
    send--;
    while (*tend++ != '\0')
        ;
    tend--;
    while (tend >= t && send >= s)
        if (*tend-- != *send--)
            return 0;
    return 1;
}

int main() {
    char *s = "string";
    char *t = "int";
    printf("strend(%s, %s) -> %d\n", s, t, strend(s, t));
}
