#include <stdio.h>

// Function to copy arrays using pointers
void copy_ptr(double *target, double *source, int num) {
  for (int i = 0; i < num; i++) {
    *(target + i) = *(source + i);
  }
}

int main() {
  double source[7] = {10.1, 20.2, 30.3, 40.4, 50.5, 60.6, 70.7};
  double target[3];

  // Copy the third through fifth elements from source to target
  // Note: Array indexing starts at 0, so the third element is at index 2
  copy_ptr(target, source + 2, 3);

  // Output results to verify the copy
  printf("Elements copied to target array: ");
  for (int i = 0; i < 3; i++) {
    printf("%.1f ", target[i]);
  }
  printf("\n");

  return 0;
}
