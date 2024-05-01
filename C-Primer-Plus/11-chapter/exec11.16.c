#include <ctype.h>
#include <stdio.h>
#include <string.h>

void process_input(int (*char_process_func)(int)) {
  int c;
  while ((c = getchar()) != EOF) {
    putchar(char_process_func(c));
  }
}

int main(int argc, char *argv[]) {
  // Default behavior if no arguments are provided or the argument is '-p'
  int (*process_func)(int) = toascii;

  if (argc > 1) {
    if (strcmp(argv[1], "-u") == 0) {
      process_func = toupper;
    } else if (strcmp(argv[1], "-l") == 0) {
      process_func = tolower;
    }
  }

  process_input(process_func);

  return 0;
}
