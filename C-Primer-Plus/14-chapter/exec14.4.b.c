#include <stdio.h>
#include <string.h>

typedef struct {
  char firstName[30];
  char middleName[30];
  char lastName[30];
} Name;

typedef struct {
  int ssn;
  Name name;
} Person;

void printPerson(Person p) {
  printf("%s, %s ", p.name.lastName, p.name.firstName);
  if (strlen(p.name.middleName) > 0) {
    printf("%c. ", p.name.middleName[0]);
  }
  printf("— %d\n", p.ssn);
}

int main() {
  Person people[5] = {{302039823, {"Flossie", "Mae", "Dribble"}},
                      {302039824, {"John", "A", "Smith"}},
                      {302039825, {"Jane", "", "Doe"}},
                      {302039826, {"Emily", "Elizabeth", "Jones"}},
                      {302039827, {"Bruce", "Wayne", "Lee"}}};

  for (int i = 0; i < 5; i++) {
    printPerson(people[i]);
  }

  return 0;
}
