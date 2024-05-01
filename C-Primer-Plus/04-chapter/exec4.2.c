#include <stdio.h>
#include <string.h>

int main() {
  char firstName[20];

  // Prompt user for first name
  printf("Enter your first name: ");
  scanf("%19s", firstName);

  // Print first name enclosed in double quotation marks
  printf("\"%s\"\n", firstName);

  // Print first name in a field 20 characters wide, enclosed in quotes,
  // right-justified
  printf("%20s\n", firstName);

  // Print first five characters left-justified in a field of width 7
  printf("%-7.5s\n", firstName);

  // Print first name at the left end of a field 20 characters wide, enclosed in
  // quotes
  printf("\"%-20s\"\n", firstName);

  // Print first name in a field three characters wider than the name
  printf("%*s\n", (int)strlen(firstName) + 3, firstName);

  return 0;
}