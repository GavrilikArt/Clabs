#include "main.h"
#include <stdio.h>
#include <stdlib.h>

const double buyUS = 2.58;
const double sellUS = 2.64;
const double profitUS = (2.64 - 2.58) * 100;
const double buyEU = 3.115;
const double sellEU =	3.175;
const double profitEU = (3.175 - 3.115) * 100 * 0.83;
const double buyRUB = 0.0352;
const double sellRUB = 0.0354;
const double profitRUB = (0.0354 - 0.0352) * 73.88 * 100;
const double profitArr[3] = {profitEU, profitRUB, profitUS};

int main() {
  inputInBYN();
  mainMenu();
  return 0;
}

void inputInBYN() {
  printf("%s", "\n\n\n\n\n\n\n");
  printf("%s", "Input the sum in BYN: \n");
  scanf("%lf", &sumInBYN);
  printf("%s", "\n\n\n\n\n\n\n\n\n\n\n");
  mainMenu();
}

void mainMenu() {
  printf("%s", "\n\n\n\n\n\n\n");
  printf("%s", "Choose What you want to do next:\n1. Convert to a different currency\n2. Print currency chart\n3. Get profit per 100$ for every exchange\n4. Short information about the bank\n5. Input New sum in BYN\n6. exit\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      convertInto();
      break;
    case 2:
      printTable();
      break;
    case 3:
      calculateIncome();
      break;
    case 4:
      information();
      break;
    case 5:
      inputInBYN();
      break;
    case 6:
      printf("%s", "GoodBye");
      exit(0);
    default:
      printf("Check the typing\n");
      mainMenu();
      break;
  }
}

void convertInto() {
  printf("%s", "Choose the currency:\n1. US\n2. EU\n3. RUB\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("\nConverted to US: %.2lf\n", sumInBYN/sellUS);
      break;
    case 2:
      printf("\nConverted to EU: %.2lf\n", sumInBYN/sellEU);
      break;
    case 3:
      printf("\nConverted to RUB: %.2lf\n", sumInBYN/sellRUB);
      break;
    default:
      convertInto();
  }
  backToMainMenu();
}

void printTable() {
  printf("%s", "\n\n\n\n\n\n\n\n\n\n\n");
  printf("US buy: %.2lf, US sell: %.2lf\nEU buy: %.2lf, EU sell: %.2lf\nRUB buy: %.2lf, RUB sell: %.2lf\n", buyUS, sellUS, buyEU, sellEU, buyRUB, sellRUB);
  printf("Back to main menu?\n1: Yeah\n2: No\n");
  backToMainMenu();
}

void calculateIncome() {
  printf("%s", "\n\n\n\n\n\n\n\n\n\n\n");
  printf("The income for every currency per 100$:\nUS: %.2lf\nEU: %.2lf\nRUS: %.2lf\n", profitUS, profitEU, profitRUB);
  getTheBestCurrency();
  backToMainMenu();
}

void getTheBestCurrency() {
  int maxIndex = 0;
  double max = profitArr[1];
  for (int i = 1; i < 3; ++i) {
    if (profitArr[i] > max) {
      maxIndex = i;
    }
  }

  switch (maxIndex) {
    case 0:
      printf("By the way, the best currency is EU! Profit: %.2lf\n", profitEU);
    case 1:
      printf("By the way, the best currency is RUB! Profit: %.2lf\n", profitRUB);
    case 2:
      printf("By the way, the best currency is US! Profit: %.2lf\n", profitUS);
  }
}

void information() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("Bank's name: Prior\n Main office: ...\n some more info...\n\n why th are you asking me,just visit their website..\n Probably something like https://priorbank.com but i am not sure so just google it\n");
  backToMainMenu();
}

void backToMainMenu() {
  printf("\n\n");
  printf("Back to main menu?\n1: Yeah\n2: No\n");
  int choice1;
  scanf("%d", &choice1);
  switch (choice1) {
    case 1:
      mainMenu();
      break;
    case 2:
      exit(0);
    default:
      exit(0);
  }
}

double someKindOfTest(double k) {
  return buyUS * k;
}



