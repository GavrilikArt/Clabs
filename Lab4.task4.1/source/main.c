#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int intInput() {
  int x;
  char ch;
  while (scanf("%d%c", &x, &ch) != 2 || ch != '\n' || x < 1 || x > 1000) {
    printf("Enter correct int\n");
    while (getchar() != '\n') {
    }
  }
  return x;
}

void higherOrLowerCase(bool flag, char string[]) {
  int i = 0;
  if (flag) {
    while (string[i]) {
      string[i] = toupper(string[i]);
      i++;
    }
  } else {
    while (string[i]) {
      string[i] = tolower(string[i]);
      i++;
    }
  }
}

bool containsRepeatedChars(char string[]) {
  int length = strlen(string);
  char str[length];
  strcpy(str, string);
  int index = 0;
  while (str[index]) {
    str[index] = tolower(str[index]);
    index++;
  }
  int i = 0;
  int j = 0;
  for (i; i < length - 1; ++i) {
    for (j = i + 1; j < length; ++j) {
      if (str[i] == str[j]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int number_of_matrices;
  printf("Enter number of matrices: ");
  number_of_matrices = intInput();
  while (number_of_matrices > 0) {
    number_of_matrices--;
    int n, m, i, j, k;
    printf("Enter n: ");
    n = intInput();
    printf("Enter m: ");
    m = intInput();
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        char string[1000];
        scanf("%s", string);
        bool flag = containsRepeatedChars(string);
        higherOrLowerCase(flag, string);
        printf("%s\n", string);
      }
      printf("\n");
    }
  }
  getchar();
  return 0;
}