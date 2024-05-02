#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
  int number_of_words;
  char **words;
  char temp_word[MAX_WORD_LENGTH];

  printf("How many words do you wish to enter? ");
  scanf("%d", &number_of_words);
  getchar(); // Consume the newline character after the integer input

  // Allocate memory for the array of pointers
  words = (char **)malloc(number_of_words * sizeof(char *));
  if (words == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  printf("Enter %d words now:\n", number_of_words);
  for (int i = 0; i < number_of_words; i++) {
    fgets(temp_word, MAX_WORD_LENGTH, stdin);
    // Remove newline character, if any
    temp_word[strcspn(temp_word, "\n")] = '\0';

    // Allocate memory to store the actual word
    words[i] = (char *)malloc(strlen(temp_word) + 1); // +1 for null terminator
    if (words[i] == NULL) {
      fprintf(stderr, "Memory allocation failed for word %d\n", i + 1);
      // Free previously allocated memory
      while (i-- > 0) {
        free(words[i]);
      }
      free(words);
      return 1;
    }

    // Copy the word from the temporary array to the allocated storage
    strcpy(words[i], temp_word);
  }

  printf("Here are your words:\n");
  for (int i = 0; i < number_of_words; i++) {
    printf("%s\n", words[i]);
  }

  // Free the allocated memory
  for (int i = 0; i < number_of_words; i++) {
    free(words[i]);
  }
  free(words);

  return 0;
}
