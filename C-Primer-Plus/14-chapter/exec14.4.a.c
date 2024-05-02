#include <stdio.h>
#include <string.h>

typedef struct {
  char firstName[30];
  char middleName[30];
  char lastName[30];
} Name;

typedef struct {
  int ssn; // Assuming social security number can fit into an int for simplicity
  Name name;
} Person;

void printPersons(Person people[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%s, %s ", people[i].name.lastName, people[i].name.firstName);
    if (strlen(people[i].name.middleName) > 0) {
      printf("%c. ", people[i].name.middleName[0]);
    }
    printf("— %d\n", people[i].ssn);
  }
}

int main() {
  Person people[5] = {{302039823, {"Flossie", "Mae", "Dribble"}},
                      {302039824, {"John", "A", "Smith"}},
                      {302039825, {"Jane", "", "Doe"}},
                      {302039826, {"Emily", "Elizabeth", "Jones"}},
                      {302039827, {"Bruce", "Wayne", "Lee"}}};

  printPersons(people, 5);

  return 0;
}
