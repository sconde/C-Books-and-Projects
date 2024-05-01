#include <stdio.h>

// Function to copy arrays using array notation
void copy_arr(double target[], double source[], int num) {
  for (int i = 0; i < num; i++) {
    target[i] = source[i];
  }
}

// Function to copy arrays using pointers
void copy_ptr(double *target, double *source, int num) {
  for (int i = 0; i < num; i++) {
    *(target + i) = *(source + i);
  }
}

// Function to copy arrays using pointers and an end pointer
void copy_ptrs(double *target, double *source, double *source_end) {
  while (source < source_end) {
    *target = *source;
    target++;
    source++;
  }
}

int main() {
  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target1[5];
  double target2[5];
  double target3[5];

  // Copy using array notation
  copy_arr(target1, source, 5);

  // Copy using pointers
  copy_ptr(target2, source, 5);

  // Copy using pointers with end pointer
  copy_ptrs(target3, source, source + 5);

  // Output results to verify copies
  printf("Target1: ");
  for (int i = 0; i < 5; i++) {
    printf("%.1f ", target1[i]);
  }
  printf("\nTarget2: ");
  for (int i = 0; i < 5; i++) {
    printf("%.1f ", target2[i]);
  }
  printf("\nTarget3: ");
  for (int i = 0; i < 5; i++) {
    printf("%.1f ", target3[i]);
  }
  printf("\n");

  return 0;
}
