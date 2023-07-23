#include "calculator.h"
#define MAXOP 100      /* max size of an operator or operand */
#define NUMBER '0'     /* type of a number input */
#define GET_VAR '1'    /* type of a variable get input */
#define SET_VAR '2'    /* type of a variable set input */
#define ERROR_TYPE '3' /* type of erroneous input */

/* reverse Polish calculator */
int main(int argc, char *argv[]) {
  int type;
  double op2, last;
  char s[MAXOP];
  double vars[26];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case SET_VAR:
      vars[s[0] - 'a'] = pop();
      break;
    case GET_VAR:
      push(vars[s[0] - 'a']);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: division by zero\n");
      }
      break;
    case '%':
      op2 = pop();
      push((int)pop() % (int)op2);
      break;
    case 'S':
      push(sin(pop()));
      break;
    case 'E':
      push(exp(pop()));
      break;
    case 'P':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    case 'L':
      push(last);
      break;
    case '\n':
      last = pop();
      printf("\t%.8g\n", last);
      break;
    default:
      printf("unknown command: %s\n", s);
      break;
    }
  }
  return 0;
}

int getop(char *s) {
  char c;
  static char pushback = EOF;

  if (pushback != EOF) {
    c = pushback;
    pushback = EOF;
  } else {
    c = getch();
  }
  // skip whitespace
  s[0] = c;
  while ((s[0] = c) == ' ' || c == '\t')
    c = getch();
  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-') {
    if (c == 'g') {
      s[0] = getch();
      if (s[0] < 'a' || s[0] > 'z')
        return ERROR_TYPE;
      // return get variable type
      return GET_VAR;
    } else if (c == 's') {
      s[0] = getch();
      if (s[0] < 'a' || s[0] > 'z')
        return ERROR_TYPE;
      // return get variable type
      return SET_VAR;
    } else {
      // return operator (or other non-digit char)
      return c;
    }
  }

  int i = 0;
  // collecting integer part
  if (isdigit(c) || c == '-') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  // collecting fraction part if present
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';
  if (c != EOF) {
    pushback = c;
  }

  return NUMBER;
}
