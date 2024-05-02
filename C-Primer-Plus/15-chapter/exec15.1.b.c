#include <stdio.h>
#include <stdlib.h>

int main() {
  char *pbinary = "01001001";
  int decimal = strtol(pbinary, NULL, 2);
  printf("The decimal value of %s is %d\n", pbinary, decimal);
  return 0;
}
