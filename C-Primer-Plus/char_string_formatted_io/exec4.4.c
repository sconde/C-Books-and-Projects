#include <stdio.h>

int main() {
  char name[50];
  float heightInInches, heightInFeet;

  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter your height in inches: ");
  scanf("%f", &heightInInches);

  heightInFeet = heightInInches / 12.0;

  printf("%s, you are %.3f feet tall\n", name, heightInFeet);

  return 0;
}