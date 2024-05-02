#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45 // size of array to hold title

struct film {
  char title[TSIZE];
  int rating;
  struct film *next; // points to next struct in list
  struct film *prev; // points to previous struct in list
};

int main(void) {
  struct film *head = NULL;
  struct film *prev, *current;
  char input[TSIZE];

  puts("Enter first movie title:");
  while (gets(input) != NULL && input[0] != '\0') {
    current = (struct film *)malloc(sizeof(struct film));
    if (head == NULL) { // first structure
      head = current;
      current->prev = NULL;
    } else { // subsequent structures
      prev->next = current;
      current->prev = prev;
    }
    current->next = NULL;
    strcpy(current->title, input);
    puts("Enter your rating <0-10>:");
    scanf("%d", &current->rating);
    while (getchar() != '\n')
      continue; // clear input line
    puts("Enter next movie title (empty line to stop):");
    prev = current;
  }

  // Display the list in original order
  puts("Here is the movie list:");
  current = head;
  while (current != NULL) {
    printf("Movie: %s  Rating: %d\n", current->title, current->rating);
    current = current->next;
  }

  // Display the list in reverse order
  if (head != NULL) {
    puts("Here is the movie list in reverse:");
    current = prev; // last node
    while (current != NULL) {
      printf("Movie: %s  Rating: %d\n", current->title, current->rating);
      current = current->prev;
    }
  }

  // Free allocated memory
  current = head;
  while (current != NULL) {
    prev = current;
    current = current->next;
    free(prev);
  }

  return 0;
}
