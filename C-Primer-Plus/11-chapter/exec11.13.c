#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Reversed command-line arguments:\n");
  // Start from argc - 1 because argc includes the program name itself
  for (int i = argc - 1; i > 0; i--) {
    printf("%s ", argv[i]);
  }
  printf("\n");

  return 0;
}
