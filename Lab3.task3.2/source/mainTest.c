#include "main.h"
#include <assert.h>

void test() {
  int arr[3] = {1, 2, 3};
  int arr1[3] = {1, 2, 2};
  int arr2[8] = {1, 2, 3, 4, 5, 8, 10, 11};
  int arr3[8] = {1, 3, 2, 5, 2, 10, 39, 40};
  int arr4[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int arr5[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  assert(compare(arr, arr1, 3) == 0);
  assert(compare(arr2, arr3, 8) == 0);
  assert(compare(arr5, arr4, 8) == 1);
}

#undef main
int main() {
  test();
}
