#include <math.h>
#include <stdio.h>

void Temperatures(double fahrenheit) {
  const double CELSIUS_SCALE = 5.0 / 9.0;
  const double KELVIN_OFFSET = 273.16;

  const double FAHRENHEIT_OFFSET = 32.0;
  double celsius = CELSIUS_SCALE * (fahrenheit - FAHRENHEIT_OFFSET);
  double kelvin = celsius + KELVIN_OFFSET;

  printf("Fahrenheit: %.2lf\n", fahrenheit);
  printf("Celsius: %.2lf\n", celsius);
  printf("Kelvin: %.2lf\n", kelvin);
}

int main() {
  double fahrenheit = NAN;

  printf("Enter a Fahrenheit temperature (q to quit): ");
  while (scanf("%lf", &fahrenheit) == 1) {
    Temperatures(fahrenheit);
    printf("Enter another Fahrenheit temperature (q to quit): ");
  }

  return 0;
}