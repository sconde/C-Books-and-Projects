#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <original_file> <copy_file>\n", argv[0]);
    return 1;
  }

  FILE *original_file = fopen(argv[1], "rb");
  if (original_file == NULL) {
    printf("Error opening original file.\n");
    return 1;
  }

  FILE *copy_file = fopen(argv[2], "wb");
  if (copy_file == NULL) {
    printf("Error creating copy file.\n");
    fclose(original_file);
    return 1;
  }

  int ch;
  while ((ch = fgetc(original_file)) != EOF) {
    fputc(ch, copy_file);
  }

  fclose(original_file);
  fclose(copy_file);

  printf("File copied successfully.\n");

  return 0;
}