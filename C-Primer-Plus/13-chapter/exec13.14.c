#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

// Function to map integers to specific characters
char get_char_for_intensity(int value) {
  const char *levels = " .:-=+*#%@";
  return levels[value];
}

// De-glitching function to adjust pixel values
void deglitch(int grid[ROWS][COLS]) {
  int original[ROWS][COLS];
  // Copy original grid to temporary grid for safe calculations
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      original[i][j] = grid[i][j];
    }
  }

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int neighbors[4] = {0};
      int count = 0;
      int sum = 0;

      // Collecting neighbors
      if (i > 0) {
        neighbors[count++] = original[i - 1][j];
      }
      if (i < ROWS - 1) {
        neighbors[count++] = original[i + 1][j];
      }
      if (j > 0) {
        neighbors[count++] = original[i][j - 1];
      }
      if (j < COLS - 1) {
        neighbors[count++] = original[i][j + 1];
      }

      // Check each neighbor to see if adjustment is needed
      int glitch = 1;
      for (int k = 0; k < count; k++) {
        sum += neighbors[k];
        if (abs(original[i][j] - neighbors[k]) <= 1) {
          glitch = 0;
          break;
        }
      }

      // If a glitch is found, replace with the average of neighbors
      if (glitch && count > 0) {
        grid[i][j] = (int)round((double)sum / count);
      }
    }
  }
}

int main() {
  FILE *inputFile, *outputFile;
  char filename[100];
  int image[ROWS][COLS];

  printf("Enter the input file name: ");
  scanf("%99s", filename);

  inputFile = fopen(filename, "r");
  if (!inputFile) {
    perror("Failed to open input file");
    return EXIT_FAILURE;
  }

  outputFile = fopen("output.txt", "w");
  if (!outputFile) {
    perror("Failed to open output file");
    fclose(inputFile);
    return EXIT_FAILURE;
  }

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      fscanf(inputFile, "%d", &image[i][j]);
    }
  }

  // Apply de-glitching to the image data
  deglitch(image);

  // Output the deglitched image
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      char ch = get_char_for_intensity(image[i][j] / 2);
      printf("%c", ch);
      fprintf(outputFile, "%c", ch);
    }
    printf("\n");
    fprintf(outputFile, "\n");
  }

  fclose(inputFile);
  fclose(outputFile);
  printf("Conversion complete. Check output.txt for results.\n");

  return 0;
}
