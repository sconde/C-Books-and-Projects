#include <stdarg.h> // Required for va_start, va_arg, and va_end
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show_array(const double arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%f ", arr[i]);
  }
  printf("\n");
}

double *new_d_array(int n, ...) {
  double *array = malloc(n * sizeof(double));
  if (array == NULL) {
    return NULL; // Return NULL if memory allocation fails
  }

  va_list args;
  va_start(args,
           n); // Initialize args to retrieve the additional arguments after n
  for (int i = 0; i < n; i++) {
    array[i] = va_arg(args, double);
  }
  va_end(args); // Clean up the list

  return array;
}

int main() {
  double *p1;
  double *p2;

  p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
  p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);

  show_array(p1, 5);
  show_array(p2, 4);

  free(p1);
  free(p2);

  return 0;
}
