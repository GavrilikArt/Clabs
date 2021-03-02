#include <stdio.h>
#include <math.h>
#include "main.h"

#define IAmStillAlive 1

int main() {
  printf("Input x:\n");
  double x;
  scanf("%lf", &x);
  double sinX = sin(x);

  printf("Input epsilon please\n");
  double eps;
  scanf("%lf", &eps);

  int N = 0;

  while (IAmStillAlive) {
    double current = 0;

    int i;
    for (i = 0; i <= N; ++i) {
      double numerator = pow(x, 2.0 * i + 1);
      double denominator = factorial(2 * i + 1);
      double incr = numerator / denominator;

      if (i % 2 == 1) {
        current -= incr;
      } else {
        current += incr;
      }
    }
    if (fabs(sinX - current) <= eps) {
      break;
    }
    ++N;
  }

  printf("sin(x) - Tailor row(sin(x)) = %lf, with N = %d", eps, N);
  return 0;
}

double factorial(char a) {
  double res = 1;
  char i;
  for (i = 1; i <= a; ++i) {
    res *= i;
  }
  return res;
}
