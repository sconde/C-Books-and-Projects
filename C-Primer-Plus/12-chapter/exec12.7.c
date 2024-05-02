#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides) { return rand() % sides + 1; }

void print_dice_rolls(int sets, int num_dice, int sides) {
  for (int i = 0; i < sets; i++) {
    int sum = 0;
    for (int j = 0; j < num_dice; j++) {
      sum += roll_dice(sides);
    }
    printf("%d ", sum);
    if ((i + 1) % 5 == 0) // Newline every 5 sets for better readability
      printf("\n");
  }
  printf("\n");
}

int main(void) {
  srand(time(NULL)); // Seed the random number generator

  while (1) {
    int sets, sides, num_dice;
    printf("Enter the number of sets; enter q to stop: ");
    if (scanf("%d", &sets) != 1) {
      break; // Exit the loop if input is not a number
    }

    printf("How many sides and how many dice? ");
    scanf("%d %d", &sides, &num_dice);

    printf("Here are %d sets of %d %d-sided throws.\n", sets, num_dice, sides);
    print_dice_rolls(sets, num_dice, sides);

    printf("How many sets? Enter q to stop: ");
    while (getchar() != '\n')
      ; // Clear the input buffer
  }

  printf("Finished.\n");
  return 0;
}
