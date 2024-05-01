#include <stdio.h>

int main() {
  double daphneInvestment = 100.0;
  double deirdreInvestment = 100.0;
  double daphneInterest = 0.10;
  double deirdreInterest = 0.05;
  int years = 0;

  while (deirdreInvestment <= daphneInvestment) {
    daphneInvestment += daphneInvestment * daphneInterest;
    deirdreInvestment += deirdreInvestment * deirdreInterest;
    years++;
  }

  printf("It takes %d years for Deirdre's investment to exceed Daphne's "
         "investment.\n",
         years);
  printf("Daphne's investment: $%.2f\n", daphneInvestment);
  printf("Deirdre's investment: $%.2f\n", deirdreInvestment);

  return 0;
}