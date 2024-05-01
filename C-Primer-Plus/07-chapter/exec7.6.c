#include <stdio.h>

int main() {
  char input;
  int count = 0;
  char prev = '\0';

  printf("Enter input (end with '#'): ");

  while ((input = getchar()) != '#') {
    if (prev == 'e' && input == 'i') {
      count++;
    }
    prev = input;
  }

  printf("The sequence 'ei' occurs %d times.\n", count);

  return 0;
}