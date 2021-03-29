//
// Created by apple on 3/29/21.
//
#include "main.h"
#include <assert.h>

void test() {
  assert(numOfSpaces("Hello") == 38);
  assert(numOfSpaces("Nothing") == 37);
}

#undef main
int main() {
  test();
}
