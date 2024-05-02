#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename1[100], filename2[100];
  FILE *file1, *file2;
  char *line1 = NULL, *line2 = NULL;
  size_t len1 = 0, len2 = 0;
  ssize_t read1, read2;

  // Get filenames from user input
  printf("Enter the name of the first file: ");
  scanf("%99s", filename1);
  printf("Enter the name of the second file: ");
  scanf("%99s", filename2);

  // Open files
  file1 = fopen(filename1, "r");
  if (file1 == NULL) {
    perror("Failed to open the first file");
    exit(EXIT_FAILURE);
  }
  file2 = fopen(filename2, "r");
  if (file2 == NULL) {
    perror("Failed to open the second file");
    fclose(file1);
    exit(EXIT_FAILURE);
  }

  // Read and print lines from both files alternately
  while (1) {
    read1 = getline(&line1, &len1, file1);
    read2 = getline(&line2, &len2, file2);

    if (read1 == -1 && read2 == -1) {
      break; // End of both files
    }

    if (read1 != -1) {
      printf("%s", line1); // Print line from first file
    }
    if (read2 != -1) {
      printf("%s", line2); // Print line from second file
    }
  }

  // Clean up
  free(line1);
  free(line2);
  fclose(file1);
  fclose(file2);

  return 0;
}
