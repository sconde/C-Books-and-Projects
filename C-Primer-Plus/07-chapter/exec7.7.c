#include <stdio.h>

#define BASIC_RATE 10.00
#define OVERTIME_RATE (BASIC_RATE * 1.5)
#define REGULAR_HOURS 40
#define TAX_THRESHOLD1 300
#define TAX_THRESHOLD2 150
#define TAX_RATE1 0.15
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25

double calculate_gross_pay(double hours);
double calculate_taxes(double gross);
double calculate_net_pay(double gross, double taxes);

int main() {
  double hours, gross_pay, taxes, net_pay;

  printf("Enter the number of hours worked this week: ");
  scanf("%lf", &hours);

  gross_pay = calculate_gross_pay(hours);
  taxes = calculate_taxes(gross_pay);
  net_pay = calculate_net_pay(gross_pay, taxes);

  printf("\nGross Pay: $%.2f\n", gross_pay);
  printf("Taxes: $%.2f\n", taxes);
  printf("Net Pay: $%.2f\n", net_pay);

  return 0;
}

double calculate_gross_pay(double hours) {
  if (hours > REGULAR_HOURS) {
    return REGULAR_HOURS * BASIC_RATE + (hours - REGULAR_HOURS) * OVERTIME_RATE;
  } else {
    return hours * BASIC_RATE;
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
