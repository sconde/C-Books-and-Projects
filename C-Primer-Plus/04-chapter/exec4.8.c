#include <stdio.h>

#define MILES_TO_KM 1.609
#define GALLONS_TO_LITERS 3.785

int main() {
  float miles, gallons;
  float mpg, lp100km;

  printf("Enter the number of miles traveled: ");
  scanf("%f", &miles);

  printf("Enter the number of gallons of gasoline consumed: ");
  scanf("%f", &gallons);

  mpg = miles / gallons;
  lp100km = (100 * GALLONS_TO_LITERS) / (miles * MILES_TO_KM);

  printf("Miles per gallon: %.1f\n", mpg);
  printf("Liters per 100 kilometers: %.1f\n", lp100km);

  return 0;
}