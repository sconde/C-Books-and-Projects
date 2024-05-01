#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 10
#define MAX_LENGTH 100

// Function to compare strings for qsort in ASCII sequence
int compare_strings(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

// Function to compare strings by length
int compare_length(const void *a, const void *b) {
  return strlen(*(const char **)a) - strlen(*(const char **)b);
}

// Function to compare strings by the length of the first word
int compare_first_word_length(const void *a, const void *b) {
  const char *first = *(const char **)a;
  const char *second = *(const char **)b;
  int first_length = strcspn(first, " \n\t");
  int second_length = strcspn(second, " \n\t");
  return first_length - second_length;
}

// Function to print the array of strings
void print_strings(char *strings[], int count) {
  for (int i = 0; i < count; i++) {
    printf("%s\n", strings[i]);
  }
}

int main() {
  char *strings[MAX_STRINGS];
  char buffer[MAX_LENGTH];
  int numStrings = 0;
  int option;

  printf("Enter up to 10 strings (Enter an empty line to stop):\n");
  while (numStrings < MAX_STRINGS && fgets(buffer, MAX_LENGTH, stdin) &&
         buffer[0] != '\n') {
    strings[numStrings] = strdup(buffer);
    numStrings++;
  }

  do {
    printf("\nMenu:\n");
    printf("1. Print the original list of strings\n");
    printf("2. Print strings in ASCII collating sequence\n");
    printf("3. Print strings in order of increasing length\n");
    printf("4. Print strings by the length of the first word\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    getchar(); // consume newline after number

    switch (option) {
    case 1:
      print_strings(strings, numStrings);
      break;
    case 2:
      qsort(strings, numStrings, sizeof(char *), compare_strings);
      print_strings(strings, numStrings);
      break;
    case 3:
      qsort(strings, numStrings, sizeof(char *), compare_length);
      print_strings(strings, numStrings);
      break;
    case 4:
      qsort(strings, numStrings, sizeof(char *), compare_first_word_length);
      print_strings(strings, numStrings);
      break;
    case 5:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid option. Please try again.\n");
    }
  } while (option != 5);

  // Free allocated memory
  for (int i = 0; i < numStrings; i++) {
    free(strings[i]);
  }

  return 0;
}
