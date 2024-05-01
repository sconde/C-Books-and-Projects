#include <stdio.h>
#include <string.h>

int main() {
  char firstName[50];
  char lastName[50];

  printf("Enter your first name: ");
  scanf("%s", firstName);

  printf("Enter your last name: ");
  scanf("%s", lastName);

  int firstNameLength = strlen(firstName);
  int lastNameLength = strlen(lastName);

  printf("%s %s %d\n", firstName, lastName, firstNameLength + lastNameLength);
  printf("%-*s %-*s %d\n", firstNameLength, firstName, lastNameLength, lastName,
         firstNameLength + lastNameLength);

  return 0;
}