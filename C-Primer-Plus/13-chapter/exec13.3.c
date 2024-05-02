#include <ctype.h>
#include <stdio.h>

int main() {
  char sourceFileName[100];
  char outputFileName[100];
  FILE *sourceFile;
  FILE *outputFile;
  char ch;

  // Prompt the user for the source file name
  printf("Enter the name of the source file: ");
  scanf("%s", sourceFileName);

  // Prompt the user for the output file name
  printf("Enter the name of the output file: ");
  scanf("%s", outputFileName);

  // Open the source file in read mode
  sourceFile = fopen(sourceFileName, "r");
  if (sourceFile == NULL) {
    printf("Error opening the source file.\n");
    return 1;
  }

  // Open the output file in write mode
  outputFile = fopen(outputFileName, "w");
  if (outputFile == NULL) {
    printf("Error opening the output file.\n");
    fclose(sourceFile);
    return 1;
  }

  // Copy the contents of the source file to the output file
  while ((ch = fgetc(sourceFile)) != EOF) {
    fputc(toupper(ch), outputFile);
  }

  // Close the files
  fclose(sourceFile);
  fclose(outputFile);

  printf("File copied successfully.\n");

  return 0;
}