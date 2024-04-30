#include <stdio.h>

void two() { printf("two\n"); }

void one_three() {
  printf("one\n");
  two();
  printf("three\n");
}

int main() {
  printf("starting now: ");
  one_three();
  printf("done!\n");
  return 0;
}