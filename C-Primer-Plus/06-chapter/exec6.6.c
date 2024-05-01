#include <stdio.h>

int main() {
  int lower, upper;

  printf("Enter the lower limit: ");
  scanf("%d", &lower);

  printf("Enter the upper limit: ");
  scanf("%d", &upper);

  // Printing the header of the table
  printf("Number\tSquare\tCube\n");

  // Loop through the range from lower to upper
  for (int i = lower; i <= upper; i++) {
    int square = i * i;
    int cube = i * i * i;
    printf("%d\t%d\t%d\n", i, square, cube);
  }

  return 0;
}
