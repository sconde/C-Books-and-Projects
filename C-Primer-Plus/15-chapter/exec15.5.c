#include <stdio.h>

unsigned int rotate_l(unsigned int num, int bits) {
  int size = sizeof(unsigned int) * 8; // Number of bits in an unsigned int
  bits = bits % size;                  // Ensure bits is within range

  // Perform left rotation
  return (num << bits) | (num >> (size - bits));
}

int main() {
  unsigned int num = 0x12345678; // Example input
  int rotateBits = 4;            // Number of bits to rotate

  printf("Before rotation: 0x%08X\n", num);
  num = rotate_l(num, rotateBits);
  printf("After rotation:  0x%08X\n", num);

  return 0;
}