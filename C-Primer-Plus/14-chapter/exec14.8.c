#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#define SEATS 12
#define NAME_LEN 30
#define FILENAME "seating.dat"

typedef struct {
  int id;
  int assigned;
  char lastName[NAME_LEN];
  char firstName[NAME_LEN];
} Seat;

void showMenu(void);
void showEmptySeats(const Seat seats[], int size);
void listSeats(Seat seats[], int size);
void sortSeats(Seat seats[], int size);
void assignSeat(Seat seats[], int size);
void deleteAssignment(Seat seats[], int size);
void loadData(Seat seats[], int size);
void saveData(const Seat seats[], int size);

int main() {
  Seat seats[SEATS] = {0};
  int i;
  for (i = 0; i < SEATS; i++) {
    seats[i].id = i + 1; // Initialize seat ids
  }

  loadData(seats, SEATS);

  char choice;
  do {
    showMenu();
    choice = getchar();
    while (getchar() != '\n')
      continue; // Clear buffer
    switch (choice) {
    case 'a':
      showEmptySeats(seats, SEATS);
      break;
    case 'b':
      showEmptySeats(seats, SEATS);
      break;
    case 'c':
      listSeats(seats, SEATS);
      break;
    case 'd':
      assignSeat(seats, SEATS);
      break;
    case 'e':
      deleteAssignment(seats, SEATS);
      break;
    case 'f':
      saveData(seats, SEATS);
      printf("Exiting program.\n");
      break;
    default:
      printf("Please choose a valid option.\n");
    }
  } while (choice != 'f');

  return 0;
}

void showMenu(void) {
  printf("\nTo choose a function, enter its letter label:\n");
  printf("a) Show number of empty seats\n");
  printf("b) Show list of empty seats\n");
  printf("c) Show alphabetical list of seats\n");
  printf("d) Assign a customer to a seat assignment\n");
  printf("e) Delete a seat assignment\n");
  printf("f) Quit\n");
}

void showEmptySeats(const Seat seats[], int size) {
  int count = 0, i;
  for (i = 0; i < size; i++) {
    if (!seats[i].assigned) {
      count++;
    }
  }
  printf("There are %d empty seats.\n", count);
}

void listSeats(Seat seats[], int size) {
  sortSeats(seats, size); // Sort before displaying
  int i;
  for (i = 0; i < size; i++) {
    if (seats[i].assigned) {
      printf("Seat %d: %s, %s\n", seats[i].id, seats[i].lastName,
             seats[i].firstName);
    }
  }
}

void sortSeats(Seat seats[], int size) {
  // Simple bubble sort by last name
  int i, j;
  Seat temp;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - 1 - i; j++) {
      if (strcmp(seats[j].lastName, seats[j + 1].lastName) > 0) {
        temp = seats[j];
        seats[j] = seats[j + 1];
        seats[j + 1] = temp;
      }
    }
  }
}

void assignSeat(Seat seats[], int size) {
  int id;
  printf("Enter seat ID to assign (1-%d): ", SEATS);
  scanf("%d", &id);
  while (getchar() != '\n')
    ; // Clear buffer
  if (id < 1 || id > size || seats[id - 1].assigned) {
    printf("That seat is either invalid or already assigned.\n");
    return;
  }
  printf("Enter first name: ");
  gets(seats[id - 1].firstName);
  printf("Enter last name: ");
  gets(seats[id - 1].lastName);
  seats[id - 1].assigned = 1;
  printf("Seat assigned.\n");
}

void deleteAssignment(Seat seats[], int size) {
  int id;
  printf("Enter seat ID to unassign (1-%d): ", SEATS);
  scanf("%d", &id);
  while (getchar() != '\n')
    ; // Clear buffer
  if (id < 1 || id > size || !seats[id - 1].assigned) {
    printf("That seat is either invalid or not currently assigned.\n");
    return;
  }
  seats[id - 1].assigned = 0;
  seats[id - 1].firstName[0] = '\0';
  seats[id - 1].lastName[0] = '\0';
  printf("Seat assignment deleted.\n");
}

void loadData(Seat seats[], int size) {
  FILE *file = fopen(FILENAME, "rb");
  if (file) {
    fread(seats, sizeof(Seat), size, file);
    fclose(file);
  }
}

void saveData(const Seat seats[], int size) {
  FILE *file = fopen(FILENAME, "wb");
  if (file) {
    fwrite(seats, sizeof(Seat), size, file);
    fclose(file);
  }
}
