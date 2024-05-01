#include <stdio.h>

void display_menu() {
  printf("Enter the operation of your choice:\n");
  printf("a. add            s. subtract\n");
  printf("m. multiply       d. divide\n");
  printf("q. quit\n");
}

float get_float(const char *prompt) {
  float number;
  char ch;

  printf("%s", prompt);
  while (scanf("%f", &number) != 1) {
    while ((ch = getchar()) != '\n') {
      putchar(ch); // Display the incorrect input
    }
    printf(" is not a number.\nPlease enter a number, such as 2.5, -1.7888, or "
           "3: ");
  }

  return number;
}

int main() {
  char choice;
  float first, second, result;

  while (1) {
    display_menu();
    printf("Your choice: ");
    scanf(" %c",
          &choice); // The space before %c skips any whitespace characters

    if (choice == 'q') {
      printf("Bye.\n");
      break;
    }

    switch (choice) {
    case 'a': // Addition
    case 's': // Subtraction
    case 'm': // Multiplication
    case 'd': // Division
      first = get_float("Enter first number: ");
      second = get_float("Enter second number: ");

      if (choice == 'd' && second == 0) {
        while (second == 0) {
          second = get_float("Enter a number other than 0: ");
        }
      }

      switch (choice) {
      case 'a':
        result = first + second;
        printf("%.2f + %.2f = %.2f\n", first, second, result);
        break;
      case 's':
        result = first - second;
        printf("%.2f - %.2f = %.2f\n", first, second, result);
        break;
      case 'm':
        result = first * second;
        printf("%.2f * %.2f = %.2f\n", first, second, result);
        break;
      case 'd':
        result = first / second;
        printf("%.2f / %.2f = %.2f\n", first, second, result);
        break;
      }
      break;

    default:
      printf("Invalid option. Please choose a valid operation.\n");
    }
  }

  return 0;
}
