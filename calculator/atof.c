#include "atof.h"

double atof(char s[]) {
  double val, pow;
  int i, sign, powsign;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = s[i] == '-' ? -1 : 1;
  if (s[i] == '-' || s[i] == '+') {
    i++;
  }

  for (val = 0.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
  }

  if (s[i] == '.') {
    i++;
  }

  for (pow = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    pow *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E') {
    i++;
  }

  powsign = s[i] == '-' ? 0 : 1;
  if (s[i] == '-' || s[i] == '+') {
    i++;
  }

  int powval = 0;

  for (; isdigit(s[i]); i++) {
    powval = 10 * powval + s[i] - '0';
  }

  for (int j = 0; j < powval; j++) {
    pow = powsign ? pow / 10.0 : pow * 10.0;
  }

  return sign * val / pow;
}
