#include <ctype.h> // Include ctype.h to use the isspace() function

#include <ctype.h> // Include ctype.h to use the isspace() function
#include <stdio.h>

char get_first(void) {
  int ch;

  do {
    ch = getchar();
  } while (isspace(ch)); // Use isspace to skip all whitespace characters

  return ch;
}

int main(void) {
  char result;
  printf("Enter a string (end with #): \n");
  do {
    result = get_first();
    if (result != '#') {
      printf("First non-whitespace character: %c\n", result);
    }
  } while (result != '#');

  printf("Done.\n");

  return 0;
}
