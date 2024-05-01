#include <stdio.h>

int main() {
  int arr[8];
  int i;

  // Read integers into the array
  printf("Enter eight integers:\n");
  for (i = 0; i < 8; i++) {
    scanf("%d", &arr[i]);
  }

  // Print the integers in reverse order
  printf("Integers in reverse order:\n");
  for (i = 7; i >= 0; i--) {
    printf("%d ", arr[i]);
  }

  return 0;
}