#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 255

int main() {
  char input[MAX_LENGTH];
  int length, i;

  printf("Enter a line of text: ");
  fgets(input, MAX_LENGTH, stdin);

  length = strlen(input);

  printf("Reversed line: ");
  for (i = length - 1; i >= 0; i--) {
    printf("%c", input[i]);
  }

  return 0;
}