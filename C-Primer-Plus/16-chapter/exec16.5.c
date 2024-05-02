#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pickRandom(int array[], int size, int numPicks) {
  if (numPicks > size) {
    printf("Error: More picks requested than elements available.\n");
    return;
  }

  // Initialize the random number generator
  srand((unsigned)time(NULL));

  // To ensure unique picks, we will shuffle the array and pick the first
  // `numPicks` elements
  for (int i = 0; i < size; i++) {
    int j = rand() % (size - i) + i;
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }

  // Print the first `numPicks` elements after shuffling
  for (int i = 0; i < numPicks; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  int numPicks = 5; // Change this to test different scenarios

  printf("Picking %d random numbers from the array:\n", numPicks);
  pickRandom(numbers, size, numPicks);

  return 0;
}
