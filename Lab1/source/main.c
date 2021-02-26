#include <stdio.h>
#include "main.h"

int solve(int k) {
  int b = (k - 1) / 3;
  int actualNum = 100 + b;

  if (k % 3 == 1) {
    return actualNum / 100;
  } else if (k % 3 == 2) {
    return actualNum / 10 % 10;
  } else {
    return actualNum % 10 + 1;
  }
}

int main() {
  int k;
  printf("%s", "Enter the index\n");
  scanf("%d", &k);
  printf("%d\n", solve(k));
}