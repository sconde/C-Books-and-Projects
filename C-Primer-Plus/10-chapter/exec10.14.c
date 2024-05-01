#include <stdio.h>

// Function to calculate the average of one set of values
double average_set(int n, double arr[n]) {
  double total = 0;
  for (int i = 0; i < n; i++) {
    total += arr[i];
  }
  return total / n;
}

// Function to calculate the overall average of all values
double average_all(int rows, int cols, double arr[rows][cols]) {
  double total = 0;
  int count = rows * cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      total += arr[i][j];
    }
  }
  return total / count;
}

// Function to find the largest value in the array
double find_max(int rows, int cols, double arr[rows][cols]) {
  double max = arr[0][0];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (arr[i][j] > max) {
        max = arr[i][j];
      }
    }
  }
  return max;
}

// Main program
int main() {
  const int ROWS = 3;
  const int COLS = 5;
  double data[ROWS][COLS];
  double avgs[ROWS];

  // Input data
  printf("Enter 15 values:\n");
  for (int i = 0; i < ROWS; i++) {
    printf("Enter 5 numbers for set %d: ", i + 1);
    for (int j = 0; j < COLS; j++) {
      scanf("%lf", &data[i][j]);
    }
    avgs[i] = average_set(COLS, data[i]);
  }

  double overall_avg = average_all(ROWS, COLS, data);
  double max_value = find_max(ROWS, COLS, data);

  // Output results
  for (int i = 0; i < ROWS; i++) {
    printf("Average of set %d: %.2f\n", i + 1, avgs[i]);
  }
  printf("Overall average: %.2f\n", overall_avg);
  printf("Maximum value: %.2f\n", max_value);

  return 0;
}
