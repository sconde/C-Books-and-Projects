#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Comparator function for sorting in descending order
int compare(const void *a, const void *b) {
  // Convert pointers to int pointers and dereference them to get the values
  int num1 = *(const int *)a;
  int num2 = *(const int *)b;

  // Return negative if num2 is less than num1, thus sorting in descending order
  return (num2 - num1);
}

int main() {
  int numbers[SIZE];
  int i;

  // Seed the random number generator
  srand(time(NULL));

  // Fill the array with random numbers from 1 to 10
  for (i = 0; i < SIZE; i++) {
    numbers[i] = (rand() % 10) + 1;
  }

  // Sort the array in decreasing order
  qsort(numbers, SIZE, sizeof(int), compare);

  // Print the sorted array
  printf("Sorted numbers in decreasing order:\n");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  return 0;
}
