#include <stdio.h>

int main() {
  int powersOfTwo[8];
  int i = 0;
  int power = 1;

  // Set the elements to the first eight powers of 2
  for (i = 0; i < 8; i++) {
    powersOfTwo[i] = power;
    power *= 2;
  }

  // Display the values using a do-while loop
  i = 0;
  do {
    printf("%d ", powersOfTwo[i]);
    i++;
  } while (i < 8);

  return 0;
}