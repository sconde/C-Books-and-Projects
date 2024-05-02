#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 19

typedef struct {
  char firstName[30];
  char lastName[30];
  int atBats;
  int hits;
  int walks;
  int RBIs;
  float battingAverage;
} Player;

void calculateBattingAverages(Player players[], int count) {
  for (int i = 0; i < count; i++) {
    if (players[i].atBats > 0) {
      players[i].battingAverage = (float)players[i].hits / players[i].atBats;
    }
  }
}

int main() {
  Player players[MAX_PLAYERS] = {0};
  FILE *file = fopen("baseball_stats.txt", "r");
  if (!file) {
    printf("File could not be opened.\n");
    return EXIT_FAILURE;
  }

  int number;
  char firstName[30];
  char lastName[30];
  int atBats, hits, walks, RBIs;

  while (fscanf(file, "%d %s %s %d %d %d %d", &number, firstName, lastName,
                &atBats, &hits, &walks, &RBIs) == 7) {
    if (number < 0 || number >= MAX_PLAYERS) {
      printf("Invalid player number: %d\n", number);
      continue;
    }
    strcpy(players[number].firstName, firstName);
    strcpy(players[number].lastName, lastName);
    players[number].atBats += atBats;
    players[number].hits += hits;
    players[number].walks += walks;
    players[number].RBIs += RBIs;
  }

  fclose(file);

  calculateBattingAverages(players, MAX_PLAYERS);

  printf("Player Stats:\n");
  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (players[i].atBats > 0) { // Print only if the player has played
      printf("%s %s: At Bats: %d, Hits: %d, Walks: %d, RBIs: %d, Batting "
             "Average: %.3f\n",
             players[i].firstName, players[i].lastName, players[i].atBats,
             players[i].hits, players[i].walks, players[i].RBIs,
             players[i].battingAverage);
    }
  }

  return EXIT_SUCCESS;
}
