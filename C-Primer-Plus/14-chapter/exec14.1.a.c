#include <stdio.h>
#include <string.h>

typedef struct lens {
  float foclen;   // focal length in mm
  float fstop;    // aperture
  char brand[30]; // brand name
} LENS;

int main() {
  LENS lenses[10];

  // Manually setting the third element
  lenses[2].foclen = 500.0;              // Focal length 500 mm
  lenses[2].fstop = 2.0;                 // Aperture f/2.0
  strcpy(lenses[2].brand, "Remarkatar"); // Brand name Remarkatar

  // Print the details of the third lens
  printf("Lens 3: %s, Focal Length: %.1fmm, Aperture: f/%.1f\n",
         lenses[2].brand, lenses[2].foclen, lenses[2].fstop);

  return 0;
}
