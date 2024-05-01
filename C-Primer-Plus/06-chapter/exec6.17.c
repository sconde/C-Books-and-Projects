#include <stdio.h>

int main() {
  double balance = 1000000.0;   // Initial balance
  double interestRate = 0.08;   // Annual interest rate
  double withdrawal = 100000.0; // Amount withdrawn each year
  int years = 0;                // Number of years

  while (balance > 0) {
    balance += balance * interestRate; // Add interest
    balance -= withdrawal;             // Subtract withdrawal
    years++;                           // Increment years
  }

  printf("It takes %d years for Chuckie to empty his account.\n", years);

  return 0;
}