#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

// Function to map integers to specific characters
char get_char_for_intensity(int value) {
  const char *levels = " .:-=+*#%@";
  return levels[value];
}

int main() {
  FILE *inputFile, *outputFile;
  char filename[100];

  // Ask user for the input file name
  printf("Enter the input file name: ");
  scanf("%99s", filename);

  // Open the input file
  inputFile = fopen(filename, "r");
  if (!inputFile) {
    perror("Failed to open input file");
    return EXIT_FAILURE;
  }

  // Open the output file
  outputFile = fopen("output.txt", "w");
  if (!outputFile) {
    perror("Failed to open output file");
    fclose(inputFile);
    return EXIT_FAILURE;
  }

  int value;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (fscanf(inputFile, "%d", &value) == 1) {
        char ch = get_char_for_intensity(
            value / 2); // Convert the 0-9 value to a character
        printf("%c", ch);
        fprintf(outputFile, "%c", ch);
      }
    }
    printf("\n");
    fprintf(outputFile, "\n");
  }

  // Close files
  fclose(inputFile);
  fclose(outputFile);

  printf("Conversion complete. Check output.txt for results.\n");

  return 0;
}
