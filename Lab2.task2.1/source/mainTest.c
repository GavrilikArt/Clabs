#include "main.h"
#include <assert.h>

void test() {
  assert(someKindOfTest(2.0) == 2.58 * 2.0);
}

#undef main
int main() {
  test();
}