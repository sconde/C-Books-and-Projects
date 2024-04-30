#include <stdio.h>

void br();
void ic();

int main() {
  br();
  printf("India, China ");
  ic();
  printf("\n");
  ic();
  printf("\n");
  br();
  printf("\n");

  return 0;
}

void br() { printf("Brazil, Russia "); }

void ic() { printf("India, China "); }