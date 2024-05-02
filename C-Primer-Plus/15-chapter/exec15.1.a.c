#include <stdio.h>

int binary_to_int(const char *pbinary) {
  int result = 0;
  while (*pbinary) { // Loop until '\0' (end of string)
    result = (result << 1) |
             (*pbinary - '0'); // Shift result left and add current bit
    pbinary++;                 // Move to next character
  }
  return result;
}

int main() {
  char *pbinary = "01001001";
  int decimal = binary_to_int(pbinary);
  printf("The decimal value of %s is %d\n", pbinary, decimal);
  return 0;
}
