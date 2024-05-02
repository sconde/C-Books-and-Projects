#include <stdio.h>

int getCallCount() {
  static int count = 0;
  return ++count;
}

int main() {
  int i;
  for (i = 0; i < 5; i++) {
    printf("Function called %d times\n", getCallCount());
  }
  return 0;
}