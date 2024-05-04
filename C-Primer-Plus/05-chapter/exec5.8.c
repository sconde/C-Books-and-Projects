#include <stdio.h>

int main() {
  int secondOperand = 0, firstOperand = 0;

  printf("This program computes moduli.\n");
  printf("Enter an integer to serve as the second operand: ");
  scanf("%d", &secondOperand);

  while (1) {
    printf("Now enter the first operand: ");
    scanf("%d", &firstOperand);

    if (firstOperand <= 0) {
      break;
    }

    printf("%d %% %d is %d\n", firstOperand, secondOperand,
           firstOperand % secondOperand);
    printf("Enter next number for first operand (<= 0 to quit): ");
  }

  printf("Done\n");

  return 0;
}