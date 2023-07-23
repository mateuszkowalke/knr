#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 100 /* max size of values' stack */

int sp = 0; /* next free stack position */
double stack[MAXVAL];

double pop() {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void push(double n) {
    if (sp < MAXVAL) {
        stack[sp++] = n;
    } else {
        printf("error: stack full, can't push %g\n", n);
    }
}

int main(int argc, char *argv[]) {
    int stack[256];
    int *stackp = stack;
    char **argvp = argv;
    if (argc < 2) {
        printf("expr [reversed Polish notation expression to be evaluated]");
        return EXIT_FAILURE;
    }

    while (--argc > 0) {
        printf("argvp: %s\n", *(argvp + 1));
        if (isdigit(*(++argvp)[0])) {
            push(atoi(*argvp));
        } else {
            if (strlen(*argvp) > 1)
                return printf(
                    "error: operator can be one of following: + - / *. Got %s\n", *argvp);
            int tmp;
            switch ((*argvp)[0]) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                tmp = pop();
                push(pop() - tmp);
                break;
            case '/':
                tmp = pop();
                if (tmp == 0)
                    return printf("error: zero division error\n");
                push(pop() / tmp);
                break;
            case '*':
                push(pop() * pop());
                break;
            default:
                printf("error: unrecognized operator: %c\n", (*argvp)[0]);
                return EXIT_FAILURE;
                break;
            }
        }
    }
    printf("result: %f\n", pop());

    return EXIT_SUCCESS;
}
