// pe12-2a.c
#include "exec12.2a.h"
#include <stdio.h>

static int mode;
static double distance;
static double fuel;

void set_mode(int new_mode) {
  if (new_mode != 0 && new_mode != 1) {
    printf("Invalid mode specified. Mode %d(US) used.\n", mode);
  } else {
    mode = new_mode;
  }
}

void get_info(void) {
  if (mode == 0) {
    printf("Enter distance traveled in kilometers: ");
    scanf("%lf", &distance);
    printf("Enter fuel consumed in liters: ");
    scanf("%lf", &fuel);
  } else if (mode == 1) {
    printf("Enter distance traveled in miles: ");
    scanf("%lf", &distance);
    printf("Enter fuel consumed in gallons: ");
    scanf("%lf", &fuel);
  }
}

void show_info(void) {
  if (mode == 0) {
    printf("Fuel consumption is %.2f liters per 100 km.\n",
           (fuel / distance) * 100);
  } else {
    printf("Fuel consumption is %.2f miles per gallon.\n", distance / fuel);
  }
}
