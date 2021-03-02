#include "main.h"
#include <math.h>
#include <assert.h>

void test() {
  assert(fabs(factorial(4) - 24) <= 0.00001);
  assert(fabs(factorial(6) - 720) <= 0.00001);
  assert(fabs(factorial(9) - 362880) <= 0.00001);
}

#undef main
int main() {
  test();
}