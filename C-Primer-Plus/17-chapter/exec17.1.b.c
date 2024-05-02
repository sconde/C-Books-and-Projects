#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45 // size of array to hold title

struct film {
  char title[TSIZE];
  int rating;
  struct film *next; // points to next struct in list
};

// Function prototypes
void printList(struct film *node);
void printListReverse(struct film *node);
void freeList(struct film *head);

int main(void) {
  struct film *head = NULL;
  struct film *current, *last = NULL;
  char input[TSIZE];

  // Collect and store information
  puts("Enter first movie title:");
  while (gets(input) != NULL && input[0] != '\0') {
    current = (struct film *)malloc(sizeof(struct film));
    if (head == NULL) // first structure
      head = current;
    else // subsequent structures
      last->next = current;

    current->next = NULL;
    strcpy(current->title, input);

    puts("Enter your rating <0-10>:");
    scanf("%d", &current->rating);
    while (getchar() != '\n')
      continue; // clear input line

    last = current;
    puts("Enter next movie title (empty line to stop):");
  }

  // Display the list in original order
  if (head == NULL)
    printf("No data entered. ");
  else {
    puts("Here is the movie list:");
    printList(head);
  }

  // Display the list in reverse order
  puts("Here is the movie list in reverse:");
  printListReverse(head);

  // Free the allocated memory
  freeList(head);

  puts("Bye!");
  return 0;
}

void printList(struct film *node) {
  if (node == NULL)
    return;
  printf("Movie: %s  Rating: %d\n", node->title, node->rating);
  printList(node->next);
}

void printListReverse(struct film *node) {
  if (node == NULL)
    return;
  printListReverse(node->next);
  printf("Movie: %s  Rating: %d\n", node->title, node->rating);
}

void freeList(struct film *head) {
  struct film *temp;
  while (head != NULL) {
    temp = head->next;
    free(head);
    head = temp;
  }
}
