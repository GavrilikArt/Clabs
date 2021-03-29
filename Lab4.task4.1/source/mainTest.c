//
// Created by apple on 3/29/21.
//
#include "main.h"
#include <assert.h>

void test() {
  assert(containsRepeatedChars("hh" == true));
  assert(containsRepeatedChars("hello" == true));
}

#undef main
int main() {
  test();
}
