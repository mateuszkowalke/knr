#include "calculator_stack.h"

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

double peek() { return stack[sp - 1]; }

void duplicate_top() { push(peek()); }

void swap_top() {
  if (sp < 2) {
    printf("Error: less than 2 items on stack.");
  } else {
    double tmp = stack[sp - 1];
    stack[sp - 1] = stack[sp - 2];
    stack[sp - 2] = tmp;
  }
}

void clear() { sp = 0; }
