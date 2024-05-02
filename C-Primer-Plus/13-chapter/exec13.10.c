#include <stdio.h>
#include <stdlib.h>

void print_to_next_newline(FILE *file, long position) {
  int ch;

  // Move to the specified position in the file
  if (fseek(file, position, SEEK_SET) != 0) {
    perror("Failed to seek to position");
    return;
  }

  // Read and print until newline or EOF
  while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
    if (ch == '\n') {
      break;
    }
  }
}

int main() {
  char filename[100];
  FILE *file;
  long position;
  char input[100];

  // Prompt user for filename
  printf("Enter the name of the file: ");
  if (scanf("%99s", filename) != 1) {
    fprintf(stderr, "Invalid input\n");
    exit(EXIT_FAILURE);
  }

  // Open file
  file = fopen(filename, "r");
  if (file == NULL) {
    perror("Failed to open file");
    exit(EXIT_FAILURE);
  }

  // Main loop for file position input
  while (1) {
    printf("Enter a file position (negative or nonnumeric to quit): ");
    if (scanf("%99s", input) != 1) {
      fprintf(stderr, "Invalid input\n");
      break;
    }

    // Check for nonnumeric input
    if (sscanf(input, "%ld", &position) != 1 || position < 0) {
      break; // Exit if input is nonnumeric or negative
    }

    // Print from the given position to the next newline
    print_to_next_newline(file, position);
  }

  // Close the file and exit
  fclose(file);
  printf("Exiting...\n");
  return 0;
}
