#include <math.h> // For pow function
#include <stdio.h>
#include <stdlib.h> // For atof and atoi

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <base> <exponent>\n", argv[0]);
    return 1; // Return an error code
  }

  double base = atof(argv[1]);  // Convert the first argument to double
  int exponent = atoi(argv[2]); // Convert the second argument to integer

  double result = pow(base, exponent); // Calculate base^exponent

  printf("%.2f^%d = %.2f\n", base, exponent, result);

  return 0;
}
