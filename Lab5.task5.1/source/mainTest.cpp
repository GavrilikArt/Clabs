#include <assert.h>
#include <vector>
#include <list>
#include "main.h"

void test() {
  std::vector<int> num1 = convert("1203314");
  std::vector<int> num2 = convert("124134");
  std::vector<int> ans = convert("9");
  assert(LongDivLong(num1, num2) == ans);
  ans = convert("1079180");
  assert(LongSubLong(num1, num2) == ans);
  std::list<int> n1 = castStrToList("12345");
  std::list<int> n2 = castStrToList("31451");
  std::list<int> ans1 = castStrToList("388262595");
  assert(LongMulLong(n1, n2) == ans1);
  ans1 = castStrToList("43796");
  assert(LongAddLong(n1, n2) == ans1);
}

#undef main
int main() {
  test();
}