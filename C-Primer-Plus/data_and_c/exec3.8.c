#include <stdio.h>

int main() {
  float cups, pints, ounces, tablespoons, teaspoons;

  printf("Enter a volume in cups: ");
  scanf("%f", &cups);

  pints = cups / 2;
  ounces = cups * 8;
  tablespoons = ounces * 2;
  teaspoons = tablespoons * 3;

  printf("Equivalent volumes:\n");
  printf("Pints: %.2f\n", pints);
  printf("Ounces: %.2f\n", ounces);
  printf("Tablespoons: %.2f\n", tablespoons);
  printf("Teaspoons: %.2f\n", teaspoons);

  return 0;
}