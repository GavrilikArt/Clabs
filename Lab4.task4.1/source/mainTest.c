//
// Created by apple on 3/29/21.
//
#include "main.h"
#include <assert.h>

void test() {
  assert(containsRepeatedChars("hh") == true);
  assert(containsRepeatedChars("hello") == true);
  assert(containsRepeatedChars("aufoaufoa") == true);
  assert(containsRepeatedChars("NoRep") == false);
}

#undef main
int main() {
  test();
}
