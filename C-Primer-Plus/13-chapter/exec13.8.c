#include <stdio.h>
#include <stdlib.h>

int count_char_in_file(FILE *fp, char ch) {
  int count = 0;
  int c;

  // Count occurrences of the character
  while ((c = fgetc(fp)) != EOF) {
    if (c == ch) {
      count++;
    }
  }
  return count;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <char> [file ...]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char target_char =
      argv[1][0]; // First argument is the character to search for
  if (argv[1][1] != '\0') {
    fprintf(stderr, "Error: First argument must be a single character\n");
    exit(EXIT_FAILURE);
  }

  if (argc == 2) {
    // No filenames given, read from standard input
    printf("Reading from standard input. Press CTRL+D to end input.\n");
    int count = count_char_in_file(stdin, target_char);
    printf("Character '%c' appears %d times in standard input.\n", target_char,
           count);
  } else {
    // Process each file
    for (int i = 2; i < argc; i++) {
      FILE *fp = fopen(argv[i], "r");
      if (fp == NULL) {
        fprintf(stderr, "Failed to open file %s\n", argv[i]);
        continue;
      }
      int count = count_char_in_file(fp, target_char);
      printf("Character '%c' appears %d times in file %s\n", target_char, count,
             argv[i]);
      fclose(fp);
    }
  }

  return EXIT_SUCCESS;
}
