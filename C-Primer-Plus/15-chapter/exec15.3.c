#include <stdio.h>

int countOnBits(int num) {
  int count = 0;

  while (num != 0) {
    if (num & 1) {
      count++;
    }
    num >>= 1;
  }

  return count;
}

int main() {
  int num = 12345;
  int onBits = countOnBits(num);

  printf("Number of 'on' bits in %d: %d\n", num, onBits);

  return 0;
}