#include <math.h>
#include <stdio.h>

// Define the function pointer type for clarity
typedef double (*func_ptr)(double);

// Function to transform elements of one array to another using a given function
void transform(const double source[], double target[], int n, func_ptr f) {
  for (int i = 0; i < n; i++) {
    target[i] = f(source[i]);
  }
}

// Example of a custom function to be used with transform
double square(double x) { return x * x; }

// Another custom function
double increment(double x) { return x + 1; }

int main() {
  double source[100];
  double target[100];

  // Initialize the source array for testing
  for (int i = 0; i < 100; i++) {
    source[i] = i / 10.0; // Generate values from 0.0, 0.1, ..., 9.9
  }

  // Apply sine function from math.h
  transform(source, target, 100, sin);
  printf("Sine transformation:\n");
  for (int i = 0; i < 10; i++) { // Display first 10 results for brevity
    printf("%.1f -> %.3f\n", source[i], target[i]);
  }

  // Apply custom square function
  transform(source, target, 100, square);
  printf("\nSquare transformation:\n");
  for (int i = 0; i < 10; i++) {
    printf("%.1f -> %.3f\n", source[i], target[i]);
  }

  // Apply custom increment function
  transform(source, target, 100, increment);
  printf("\nIncrement transformation:\n");
  for (int i = 0; i < 10; i++) {
    printf("%.1f -> %.3f\n", source[i], target[i]);
  }

  // Apply the exponential function from math.h
  transform(source, target, 100, exp);
  printf("\nExponential transformation:\n");
  for (int i = 0; i < 10; i++) {
    printf("%.1f -> %.3f\n", source[i], target[i]);
  }

  return 0;
}
