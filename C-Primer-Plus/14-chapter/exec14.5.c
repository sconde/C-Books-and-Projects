#include <stdio.h>

#define CSIZE 4 // Number of students

typedef struct {
  char firstName[20];
  char lastName[20];
} Name;

typedef struct {
  Name name;
  float grades[3];
  float average;
} Student;

void inputScores(Student *s) {
  printf("Enter scores for %s %s: ", s->name.firstName, s->name.lastName);
  scanf("%f %f %f", &s->grades[0], &s->grades[1], &s->grades[2]);
}

void calculateAverage(Student *s) {
  s->average = (s->grades[0] + s->grades[1] + s->grades[2]) / 3;
}

void printStudent(const Student s) {
  printf("%s %s: Grades: %.1f, %.1f, %.1f, Average: %.2f\n", s.name.firstName,
         s.name.lastName, s.grades[0], s.grades[1], s.grades[2], s.average);
}

void printClassAverages(const Student students[], int size) {
  float total[3] = {0};
  for (int i = 0; i < size; i++) {
    total[0] += students[i].grades[0];
    total[1] += students[i].grades[1];
    total[2] += students[i].grades[2];
  }
  printf("Class averages - Score 1: %.2f, Score 2: %.2f, Score 3: %.2f\n",
         total[0] / size, total[1] / size, total[2] / size);
}

int main() {
  Student students[CSIZE] = {{{"John", "Doe"}},
                             {{"Jane", "Doe"}},
                             {{"Alice", "Johnson"}},
                             {{"Bob", "Smith"}}};

  // Input scores
  for (int i = 0; i < CSIZE; i++) {
    inputScores(&students[i]);
  }

  // Calculate averages
  for (int i = 0; i < CSIZE; i++) {
    calculateAverage(&students[i]);
  }

  // Print student details
  for (int i = 0; i < CSIZE; i++) {
    printStudent(students[i]);
  }

  // Print class averages for each score
  printClassAverages(students, CSIZE);

  return 0;
}
