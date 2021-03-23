#include "main.h"
#include <stdio.h>


int main() {
  solve();
  return 0;
}

void bubbleSort(int list[], int n)
{
  int c, d, t;
  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (list[d] > list[d + 1]) {
        t = list[d];
        list[d] = list[d + 1];
        list[d + 1] = t;
      }
    }
  }
}


void solve() {
  printf("Input the num of rows: ");
  int rows = safeInput();
  printf("Input the num of columns: ");
  int cols = safeInput();
  int matrix[rows][cols];
  printf("Input the elements of the matrix: \n");
  int j;
  int i;
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows; j++) {
      printf("col %d, row %d: ", i + 1, j + 1);
      matrix[j][i] = safeInput();
    }
  }
  int colNum;
  for (colNum = 0; colNum < cols - 1; colNum++) {
    int arr1[rows];
    int arr2[rows];
    int count;
    for (count = colNum + 1; count < cols; count++) {
      for (j = 0; j < rows; j++) {
        arr1[j] = matrix[j][colNum];
        arr2[j] = matrix[j][count];
      }
      bubbleSort(arr1, rows);
      bubbleSort(arr2, rows);
      if (compare(arr1, arr2, rows)) {
        printf("column %d is similar to column %d\n", colNum + 1, count + 1);
      }
    }
  }
}

int safeInput() {
  int val;
  int safeInput = 0;
  while (!safeInput) {
    if (scanf("%d", &val) == 1) {
      safeInput = 1;
    } else {
      while (getchar() != '\n') {
        printf("Bad input, try again(should be and int!)\n");
      }
    }
  }
  return val;
}

int compare(int arr1[], int arr2[], int n) {
  int i;
  for (i = 0; i < n; ++i) {
    if (arr1[i] != arr2[i]) {
      return 0;
    }
  }
  return 1;
}

