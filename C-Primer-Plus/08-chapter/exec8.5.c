#include <stdio.h>

int main() {
  int low = 1;
  int high = 100;
  int guess = 50;
  char response;

  printf("Think of a number between 1 and 100.\n");
  printf("I will try to guess it.\n\n");

  do {
    printf("Is your number %d? (h/l/c): ", guess);
    scanf(" %c", &response);

    if (response == 'h') {
      high = guess - 1;
      guess = (low + high) / 2;
    } else if (response == 'l') {
      low = guess + 1;
      guess = (low + high) / 2;
    }
  } while (response != 'c');

  printf("\nI guessed it! Your number is %d.\n", guess);

  return 0;
}