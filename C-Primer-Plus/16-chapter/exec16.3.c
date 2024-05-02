#include <math.h>
#include <stdio.h>

typedef struct {
  double magnitude;
  double angle_degrees;
} PolarCoord;

typedef struct {
  double x;
  double y;
} RectCoord;

RectCoord polarToRectangular(PolarCoord polar) {
  RectCoord rect;
  double angle_radians =
      polar.angle_degrees * (M_PI / 180.0); // Convert degrees to radians
  rect.x = polar.magnitude * cos(angle_radians);
  rect.y = polar.magnitude * sin(angle_radians);
  return rect;
}

int main() {
  PolarCoord polar;
  RectCoord rect;

  printf("Enter the magnitude of the vector: ");
  scanf("%lf", &polar.magnitude);
  printf("Enter the angle in degrees from the x-axis: ");
  scanf("%lf", &polar.angle_degrees);

  rect = polarToRectangular(polar);

  printf("Rectangular coordinates:\n");
  printf("X = %.2f\n", rect.x);
  printf("Y = %.2f\n", rect.y);

  return 0;
}
