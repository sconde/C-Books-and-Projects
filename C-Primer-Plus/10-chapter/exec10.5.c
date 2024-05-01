#include <stdio.h>

double findDifference(double arr[], int size) {
  double min = arr[0];
  double max = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max - min;
}

int main() {
  double arr[] = {1.5, 2.7, 3.9, 4.2, 5.1};
  int size = sizeof(arr) / sizeof(arr[0]);

  double difference = findDifference(arr, size);

  printf("Difference between the largest and smallest elements: %.2f\n",
         difference);

  return 0;
}