#include <stdio.h>

int checkBit(int value, int bitPosition) {
  // Shift the bit at the given position to the rightmost position
  int bit = (value >> bitPosition) & 1;

  return bit;
}

int main() {
  int value = 10;      // Example value
  int bitPosition = 2; // Example bit position

  int result = checkBit(value, bitPosition);

  printf("Bit at position %d is: %d\n", bitPosition, result);

  return 0;
}