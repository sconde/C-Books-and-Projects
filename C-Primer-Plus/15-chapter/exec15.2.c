#include <stdio.h>
#include <stdlib.h>

// Helper function to convert integer to binary string
char *to_binary_string(int value, char *buffer, int buf_size) {
  buffer[buf_size - 1] = '\0'; // Null-terminate string
  for (int i = buf_size - 2; i >= 0; i--) {
    buffer[i] = (value & 1) ? '1' : '0';
    value >>= 1;
  }
  return buffer;
}

int main(int argc, char *argv[]) {
  char *binary1, *binary2;

  if (argc < 3) {
    // Not enough arguments, read interactively
    char input1[256], input2[256];
    printf("Enter first binary number: ");
    scanf("%255s", input1);
    printf("Enter second binary number: ");
    scanf("%255s", input2);
    binary1 = input1;
    binary2 = input2;
  } else {
    binary1 = argv[1];
    binary2 = argv[2];
  }

  // Convert binary strings to integers
  int num1 = strtol(binary1, NULL, 2);
  int num2 = strtol(binary2, NULL, 2);

  // Perform bitwise operations
  int and = num1 & num2;
  int or = num1 | num2;
  int xor = num1 ^ num2;
  int not_num1 = ~num1;
  int not_num2 = ~num2;

  // Convert results back to binary strings
  char binary[33];
  printf("num1 & num2: %s\n", to_binary_string(and, binary, sizeof(binary)));
  printf("num1 | num2: %s\n", to_binary_string(or, binary, sizeof(binary)));
  printf("num1 ^ num2: %s\n", to_binary_string(xor, binary, sizeof(binary)));
  printf("~num1: %s\n", to_binary_string(not_num1, binary, sizeof(binary)));
  printf("~num2: %s\n", to_binary_string(not_num2, binary, sizeof(binary)));

  return 0;
}
