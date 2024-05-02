#include <stdio.h>

int main(int argc, char *argv[]) {
  // Check if there are command line arguments
  if (argc < 2) {
    printf("No files provided.\n");
    return 0;
  }

  // Loop through the command line arguments
  for (int i = 1; i < argc; i++) {
    // Open the file
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      printf("Failed to open file: %s\n", argv[i]);
      continue;
    }

    // Read and display the file contents
    printf("File: %s\n", argv[i]);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
      putchar(ch);
    }
    printf("\n");

    // Close the file
    fclose(file);
  }

  return 0;
}