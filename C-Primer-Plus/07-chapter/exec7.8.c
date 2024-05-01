#include <stdio.h>

#define RATE1 8.75
#define RATE2 9.33
#define RATE3 10.00
#define RATE4 11.20
#define OVERTIME_RATE_MULTIPLIER 1.5
#define REGULAR_HOURS 40
#define TAX_THRESHOLD1 300
#define TAX_THRESHOLD2 150
#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25

double calculate_gross_pay(double hours, double rate);
double calculate_taxes(double gross);
double calculate_net_pay(double gross, double taxes);
void display_menu();

int main() {
  int choice;
  double rate, hours, gross_pay, taxes, net_pay;

  while (1) {
    display_menu();
    printf("Choose a pay rate or action (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      rate = RATE1;
      break;
    case 2:
      rate = RATE2;
      break;
    case 3:
      rate = RATE3;
      break;
    case 4:
      rate = RATE4;
      break;
    case 5:
      printf("Exiting program.\n");
      return 0;
    default:
      printf("Invalid input. Please enter a number between 1 and 5.\n\n");
      continue;
    }

    printf("Enter the number of hours worked this week: ");
    scanf("%lf", &hours);

    gross_pay = calculate_gross_pay(hours, rate);
    taxes = calculate_taxes(gross_pay);
    net_pay = calculate_net_pay(gross_pay, taxes);

    printf("\nGross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n\n", net_pay);
  }

  return 0;
}

void display_menu() {
  printf("*************************************************\n");
  printf("Enter the number corresponding to the desired pay rate or action:\n");
  printf("1) $8.75/hr\n");
  printf("2) $9.33/hr\n");
  printf("3) $10.00/hr\n");
  printf("4) $11.20/hr\n");
  printf("5) quit\n");
  printf("*************************************************\n");
}

double calculate_gross_pay(double hours, double rate) {
  if (hours > REGULAR_HOURS) {
    return REGULAR_HOURS * rate +
           (hours - REGULAR_HOURS) * rate * OVERTIME_RATE_MULTIPLIER;
  } else {
    return hours * rate;
  }
}

double calculate_taxes(double gross) {
  double taxes = 0.0;
  if (gross > TAX_THRESHOLD1 + TAX_THRESHOLD2) {
    taxes += TAX_RATE1 * TAX_THRESHOLD1;
    taxes += TAX_RATE2 * TAX_THRESHOLD2;
    taxes += TAX_RATE3 * (gross - TAX_THRESHOLD1 - TAX_THRESHOLD2);
  } else if (gross > TAX_THRESHOLD1) {
    taxes += TAX_RATE1 * TAX_THRESHOLD1;
    taxes += TAX_RATE2 * (gross - TAX_THRESHOLD1);
  } else {
    taxes += TAX_RATE1 * gross;
  }
  return taxes;
}

double calculate_net_pay(double gross, double taxes) { return gross - taxes; }
