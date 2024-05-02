#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

#define SEATS 12
#define FLIGHTS 4
#define NAME_LEN 30
#define FILENAME "flights.dat"

typedef struct {
  int id;
  int assigned;
  int confirmed;
  char lastName[NAME_LEN];
  char firstName[NAME_LEN];
} Seat;

typedef struct {
  int flightNumber;
  Seat seats[SEATS];
} Flight;

void showMainMenu(void);
void showFlightMenu(int flightNumber);
void manageFlight(Flight *flight);
void showEmptySeats(Seat seats[]);
void listSeats(Seat seats[]);
void assignSeat(Seat seats[]);
void deleteAssignment(Seat seats[]);
void confirmAssignment(Seat seats[]);
void loadData(Flight flights[]);
void saveData(Flight flights[]);

Flight flights[FLIGHTS] = {{102}, {311}, {444}, {519}};

int main() {
  loadData(flights);
  int choice;
  do {
    showMainMenu();
    scanf("%d", &choice);
    while (getchar() != '\n')
      ; // Clear input buffer
    if (choice >= 1 && choice <= 4) {
      manageFlight(&flights[choice - 1]);
    }
  } while (choice != 0);
  saveData(flights);
  printf("Exiting program.\n");
  return 0;
}

void showMainMenu(void) {
  printf("\nSelect a flight or exit:\n");
  for (int i = 0; i < FLIGHTS; i++) {
    printf("%d) Flight %d\n", i + 1, flights[i].flightNumber);
  }
  printf("0) Quit\n");
}

void manageFlight(Flight *flight) {
  char option;
  do {
    showFlightMenu(flight->flightNumber);
    option = getchar();
    while (getchar() != '\n')
      ; // Clear buffer
    switch (option) {
    case 'a':
      showEmptySeats(flight->seats);
      break;
    case 'b':
      listSeats(flight->seats);
      break;
    case 'c':
      assignSeat(flight->seats);
      break;
    case 'd':
      deleteAssignment(flight->seats);
      break;
    case 'e':
      confirmAssignment(flight->seats);
      break;
    case 'f':
      break; // Return to the main menu
    default:
      printf("Invalid option. Please try again.\n");
    }
  } while (option != 'f');
}

void showFlightMenu(int flightNumber) {
  printf("\nFlight %d - Choose a function:\n", flightNumber);
  printf("a) Show number of empty seats\n");
  printf("b) Show list of seats\n");
  printf("c) Assign a customer to a seat\n");
  printf("d) Delete a seat assignment\n");
  printf("e) Confirm a seat assignment\n");
  printf("f) Return to main menu\n");
}

// Implement other functions such as showEmptySeats, listSeats, assignSeat,
// deleteAssignment, confirmAssignment as needed... Ensure loadData and saveData
// handle all flights' data.
