#include <ctype.h>
#include <stdio.h>
#include <string.h>

int my_atoi(const char *str) {
  int result = 0;
  int sign = 1;

  // Skip any leading whitespace
  while (isspace(*str)) {
    str++;
  }

  // Handle possible sign
  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }

  // Convert characters to integer value
  while (*str != '\0') {
    if (isdigit(*str)) {
      result = result * 10 + (*str - '0');
      str++;
    } else {
      // If we encounter a non-digit character, return 0
      return 0;
    }
  }

  return sign * result;
}

int main() {
  char input[100];

  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  // Remove potential newline character
  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }

  int number = my_atoi(input);
  printf("Converted number: %d\n", number);

  return 0;
}
