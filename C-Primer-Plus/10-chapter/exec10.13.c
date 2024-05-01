#include <stdio.h>

#define ROWS 3
#define COLS 5

// Function to calculate the average of one set of values
double average_set(double arr[], int n) {
  double total = 0;
  for (int i = 0; i < n; i++) {
    total += arr[i];
  }
  return total / n;
}

// Function to calculate the overall average of all values
double average_all(double arr[][COLS], int rows) {
  double total = 0;
  int count = rows * COLS;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < COLS; j++) {
      total += arr[i][j];
    }
  }
  return total / count;
}

// Function to find the largest value in the array
double find_max(double arr[][COLS], int rows) {
  double max = arr[0][0];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < COLS; j++) {
      if (arr[i][j] > max) {
        max = arr[i][j];
      }
    }
  }
  return max;
}

// Main program
int main() {
  double data[ROWS][COLS];
  double avgs[ROWS];

  // Input data
  printf("Enter 15 values:\n");
  for (int i = 0; i < ROWS; i++) {
    printf("Enter 5 numbers for set %d: ", i + 1);
    for (int j = 0; j < COLS; j++) {
      scanf("%lf", &data[i][j]);
    }
    avgs[i] = average_set(data[i], COLS);
  }

  double overall_avg = average_all(data, ROWS);
  double max_value = find_max(data, ROWS);

  // Output results
  for (int i = 0; i < ROWS; i++) {
    printf("Average of set %d: %.2f\n", i + 1, avgs[i]);
  }
  printf("Overall average: %.2f\n", overall_avg);
  printf("Maximum value: %.2f\n", max_value);

  return 0;
}
