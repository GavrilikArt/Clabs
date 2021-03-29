#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void openCheck(FILE* file, FILE* file1) {
  if (file == NULL || file1 == NULL)
  {
    printf("\nUnable to open file.\n");
    printf("Please check whether file exists and you have read/write privilege.\n");
    exit(EXIT_FAILURE);
  }
}

int numOfSpaces(char string[]) {
  int len = strlen(string);
  return abs(40 - len / 2);
}

void center(char path[100]) {
  FILE * fPtr;
  FILE * fTemp;

  char buffer[BUFFER_SIZE];
  fflush(stdin);
  fPtr  = fopen(path, "r+");
  fTemp = fopen("replace.txt", "w");

  openCheck(fPtr, fTemp);

  while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
  {
    int i = 0;
    for (;i < numOfSpaces(buffer); ++i) {
      fputc(' ', fTemp);
    }
    fputs(buffer, fTemp);
  }
  fclose(fPtr);
  fclose(fTemp);
  remove(path);
  rename("replace.txt", path);
}

int main()
{
  center("input.txt");
  return 0;
}