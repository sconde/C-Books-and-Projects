#include <stdio.h>

double calculate_series(int terms, int is_alternating);

int main() {
  int terms;

  printf("Enter the number of terms to compute (enter 0 or a negative number "
         "to exit): ");
  scanf("%d", &terms);

  while (terms > 0) {
    double sum1 = calculate_series(terms, 0);
    double sum2 = calculate_series(terms, 1);

    printf("Series 1 sum after %d terms: %f\n", terms, sum1);
    printf("Series 2 sum after %d terms: %f\n", terms, sum2);

    printf("\nEnter the number of terms to compute (enter 0 or a negative "
           "number to exit): ");
    scanf("%d", &terms);
  }

  return 0;
}

double calculate_series(int terms, int is_alternating) {
  double sum = 0.0;
  for (int i = 1; i <= terms; i++) {
    if (is_alternating) {
      // Alternate the sign for the series 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 +
      // ...
      sum += (i % 2 == 0 ? -1 : 1) * 1.0 / i;
    } else {
      // Regular series 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...
      sum += 1.0 / i;
    }
  }
  return sum;
}
