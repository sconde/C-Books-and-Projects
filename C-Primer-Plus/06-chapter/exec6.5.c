#include <stdio.h>

int main() {
  char input;
  printf("Enter an uppercase letter: ");
  scanf(" %c", &input); // Read the uppercase letter

  int totalRows = input - 'A' + 1; // Calculate the number of rows

  for (int row = 0; row < totalRows; row++) {
    // Print leading spaces
    for (int space = totalRows - row; space > 1; space--) {
      printf(" ");
    }

    // Print letters in ascending order
    for (char letter = 'A'; letter < 'A' + row; letter++) {
      printf("%c", letter);
    }

    // Print letters in descending order
    for (char letter = 'A' + row; letter >= 'A'; letter--) {
      printf("%c", letter);
    }

    printf("\n");
  }
  return 0;
}
