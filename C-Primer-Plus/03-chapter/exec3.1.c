#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
  // Integer overflow
  int intOverflow = INT_MAX;
  intOverflow = intOverflow + 1;
  printf("Integer Overflow: %d\n", intOverflow);

  // Floating-point overflow
  float floatOverflow = FLT_MAX;
  floatOverflow = floatOverflow * 2;
  printf("Floating-point Overflow: %f\n", floatOverflow);

  // Floating-point underflow
  float floatUnderflow = FLT_MIN;
  floatUnderflow = floatUnderflow / 2;
  printf("Floating-point Underflow: %f\n", floatUnderflow);

  return 0;
}