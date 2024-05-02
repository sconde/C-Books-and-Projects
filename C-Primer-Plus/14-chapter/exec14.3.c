#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};

int main(void) {
  struct book library[MAXBKS]; // array of book structures
  int count = 0;
  int index;

  printf("Please enter the book title.\n");
  printf("Press [enter] at the start of a line to stop.\n");
  while (count < MAXBKS && gets(library[count].title) != NULL &&
         library[count].title[0] != '\0') {
    printf("Now enter the author.\n");
    gets(library[count].author);
    printf("Now enter the value.\n");
    scanf("%f", &library[count++].value);
    while (getchar() != '\n')
      continue; // clear input line
    if (count < MAXBKS)
      printf("Enter the next title.\n");
  }

  if (count > 0) {
    printf("\nHere is the list of your books:\n");
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
             library[index].value);

    // Sort by title
    struct book temp;
    for (int i = 0; i < count - 1; i++)
      for (int j = i + 1; j < count; j++)
        if (strcmp(library[i].title, library[j].title) > 0) {
          temp = library[i];
          library[i] = library[j];
          library[j] = temp;
        }

    printf("\nAlphabetized by title:\n");
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
             library[index].value);

    // Sort by value
    for (int i = 0; i < count - 1; i++)
      for (int j = i + 1; j < count; j++)
        if (library[i].value > library[j].value) {
          temp = library[i];
          library[i] = library[j];
          library[j] = temp;
        }

    printf("\nSorted by value:\n");
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", library[index].title, library[index].author,
             library[index].value);
  } else
    printf("No books? Too bad.\n");

  return 0;
}
