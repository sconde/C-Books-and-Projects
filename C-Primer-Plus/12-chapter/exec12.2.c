// pe12-2b.c
#include "exec12.2a.h"
#include <stdio.h>

int main(void) {
  int mode;
  printf("Enter 0 for metric mode, 1 for US mode: ");
  scanf("%d", &mode);
  while (mode >= 0) {
    set_mode(mode);
    get_info();
    show_info();
    printf("Enter 0 for metric mode, 1 for US mode (-1 to quit): ");
    scanf("%d", &mode);
  }
  printf("Done.\n");
  return 0;
}