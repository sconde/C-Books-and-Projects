#include <stdio.h>

// Function declarations
void function1();
void function2();
void function3();
void exitProgram();

// Main program
int main() {
  void (*menuFunctions[])(void) = {function1, function2, function3,
                                   exitProgram}; // Array of function pointers
  int choice;

  while (1) {
    // Display the menu
    printf("\nMenu:\n");
    printf("1. Function 1\n");
    printf("2. Function 2\n");
    printf("3. Function 3\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
      printf("Invalid choice, please choose 1-4.\n");
    } else {
      (*menuFunctions[choice - 1])(); // Call the function based on the choice
      if (choice == 4)
        break; // Break the loop if exit is chosen
    }
  }

  return 0;
}

// Definition of menu functions
void function1() { printf("Function 1 has been called.\n"); }

void function2() { printf("Function 2 has been called.\n"); }

void function3() { printf("Function 3 has been called.\n"); }

void exitProgram() { printf("Exiting program.\n"); }
