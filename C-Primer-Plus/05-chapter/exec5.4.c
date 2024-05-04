#include <math.h>
#include <stdio.h>

#define CM_TO_FEET 30.48
#define INCHES_PER_FOOT 12

int main() {
  float height_cm = NAN;

  while (1) {
    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf("%f", &height_cm);

    if (height_cm <= 0) {
      printf("Bye\n");
      break;
    }

    int feet = (int)(height_cm / CM_TO_FEET);

    float inches = (height_cm / CM_TO_FEET - feet) * INCHES_PER_FOOT;

    printf("%.1f cm = %d feet, %.1f inches\n", height_cm, feet, inches);
  }

  return 0;
}