#include <stdio.h>

typedef struct lens {
  float foclen;
  float fstop;
  char brand[30];
} LENS;

int main() {
  LENS lenses[10] = {
      [2] = {.foclen = 500.0,
             .fstop = 2.0,
             .brand = "Remarkatar"} // Initialize the third element directly
  };

  // Print the details of the third lens
  printf("Lens 3: %s, Focal Length: %.1fmm, Aperture: f/%.1f\n",
         lenses[2].brand, lenses[2].foclen, lenses[2].fstop);

  return 0;
}
