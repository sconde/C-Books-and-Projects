#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
  int is_deleted; // Flag to mark books for deletion
};

void printBooks(struct book library[], int count);
void modifyOrDeleteBook(struct book *b);

int main(void) {
  struct book library[MAXBKS] = {0};
  FILE *pbooks;
  int count = 0;
  int index, filecount;
  size_t size = sizeof(struct book);

  if ((pbooks = fopen("book.dat", "r+b")) ==
      NULL) { // Open file in r+b mode to read and write
    fputs("Cannot open book.dat file\n", stderr);
    exit(1);
  }

  // Read existing records from the file
  rewind(pbooks);
  while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
    if (count == 0) {
      puts("Current contents of book.dat:");
    }
    printf("%d: %s by %s: $%.2f\n", count, library[count].title,
           library[count].author, library[count].value);
    modifyOrDeleteBook(&library[count]); // Modify or delete the book record
    count++;
  }

  // Get new data from user
  puts("Please add new book titles.");
  puts("Press [enter] at the start of a line to stop.");
  while (count < MAXBKS && gets(library[count].title) != NULL &&
         library[count].title[0] != '\0') {
    puts("Enter the author:");
    gets(library[count].author);
    puts("Enter the value:");
    scanf("%f", &library[count].value);
    library[count].is_deleted = 0; // Mark as not deleted
    while (getchar() != '\n')      // clear input line
      continue;
    count++;
  }

  // Writing updated records back to file
  rewind(pbooks);
  for (index = 0; index < count; index++) {
    if (!library[index].is_deleted) { // Only write non-deleted records
      fwrite(&library[index], size, 1, pbooks);
    }
  }
  fclose(pbooks);

  return 0;
}

void modifyOrDeleteBook(struct book *b) {
  char response;
  printf("Modify or delete this record? (M/D): ");
  response = getchar();
  while (getchar() != '\n') // clear input line
    continue;

  if (response == 'D' || response == 'd') {
    b->is_deleted = 1; // Mark the book as deleted
  } else if (response == 'M' || response == 'm') {
    printf("Enter new title: ");
    gets(b->title);
    printf("Enter new author: ");
    gets(b->author);
    printf("Enter new value: ");
    scanf("%f", &b->value);
    while (getchar() != '\n') // clear input line
      continue;
    b->is_deleted = 0; // Ensure it is not marked as deleted
  }
}
