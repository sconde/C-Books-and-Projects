#include <stdio.h>

int main() {
  char firstName[20];
  char lastName[20];

  printf("Enter your first name: ");
  scanf("%s", firstName);

  printf("Enter your last name: ");
  scanf("%s", lastName);

  printf("Your name in the format last, first: %s, %s\n", lastName, firstName);

  return 0;
}