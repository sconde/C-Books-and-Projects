#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 255

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <search string> <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *search_string = argv[1];
  const char *filename = argv[2];
  FILE *file;
  char line[MAX_LINE_LENGTH];

  // Open the file
  file = fopen(filename, "r");
  if (file == NULL) {
    perror("Failed to open the file");
    exit(EXIT_FAILURE);
  }

  // Read and search each line
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    if (strstr(line, search_string) != NULL) {
      printf("%s", line); // Print the line if it contains the search string
    }
  }

  // Close the file
  fclose(file);

  return 0;
}
