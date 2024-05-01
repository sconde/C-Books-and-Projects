#include <stdio.h>

#define RATE1 0.15
#define RATE2 0.28

#define SINGLE_THRESHOLD 17850
#define HEAD_OF_HOUSEHOLD_THRESHOLD 23900
#define MARRIED_JOINT_THRESHOLD 29750
#define MARRIED_SEPARATE_THRESHOLD 14875

void display_menu();
double calculate_tax(int category, double income);

int main() {
  int category;
  double income, tax;

  while (1) {
    display_menu();
    printf("Enter your tax category (1-5, enter 5 to quit): ");
    scanf("%d", &category);

    if (category == 5) {
      printf("Exiting program.\n");
      break;
    }

    if (category < 1 || category > 5) {
      printf("Invalid choice. Please enter a number between 1 and 5.\n");
      continue;
    }

    printf("Enter your taxable income: $");
    scanf("%lf", &income);

    tax = calculate_tax(category, income);
    printf("Total tax owed: $%.2f\n\n", tax);
  }

  return 0;
}

void display_menu() {
  printf("\nChoose your tax category:\n");
  printf("1) Single\n");
  printf("2) Head of Household\n");
  printf("3) Married, Joint\n");
  printf("4) Married, Separate\n");
  printf("5) Quit\n");
}

double calculate_tax(int category, double income) {
  double threshold;
  switch (category) {
  case 1:
    threshold = SINGLE_THRESHOLD;
    break;
  case 2:
    threshold = HEAD_OF_HOUSEHOLD_THRESHOLD;
    break;
  case 3:
    threshold = MARRIED_JOINT_THRESHOLD;
    break;
  case 4:
    threshold = MARRIED_SEPARATE_THRESHOLD;
    break;
  default:
    printf("Invalid tax category.\n");
    return 0.0;
  }

  if (income <= threshold) {
    return RATE1 * income;
  } else {
    return RATE1 * threshold + RATE2 * (income - threshold);
  }
}
