#include <stdio.h>

int main() {
  float height_cm;

  while (1) {
    printf("Enter a height in centimeters (<=0 to quit): ");
    scanf("%f", &height_cm);

    if (height_cm <= 0) {
      printf("Bye\n");
      break;
    }

    int feet = (int)(height_cm / 30.48);
    float inches = (height_cm / 30.48 - feet) * 12;

    printf("%.1f cm = %d feet, %.1f inches\n", height_cm, feet, inches);
  }

  return 0;
}