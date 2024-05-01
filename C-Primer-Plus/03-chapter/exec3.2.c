#include <stdio.h>

int main() {
  int asciiCode;

  printf("Enter an ASCII code value: ");
  scanf("%d", &asciiCode);

  printf("The character for ASCII code %d is '%c'\n", asciiCode, asciiCode);

  return 0;
}