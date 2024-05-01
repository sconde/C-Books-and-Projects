#include <stdio.h>

#define MONTHS 12 // Number of months in a year
#define YEARS 5   // Number of years of data

int main(void) {
  // Initializing rainfall data for 2010 - 2014
  const float rain[YEARS][MONTHS] = {
      {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
      {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 3.0, 0.9, 1.4, 7.3},
      {9.1, 5.8, 5.6, 7.4, 3.2, 1.0, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1},
      {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
      {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}};

  const float(*p)[MONTHS] = rain; // Pointer to an array of MONTHS floats
  float subtot, total;

  printf(" YEAR     RAINFALL  (inches)\n");
  for (int year = 0; year < YEARS; year++) {
    subtot = 0; // Initialize the yearly subtotal
    for (int month = 0; month < MONTHS; month++) {
      subtot +=
          *(*p + month); // Sum rainfall for a month using pointer dereferencing
    }
    printf("%5d %15.1f\n", 2010 + year, subtot);
    total += subtot; // Add to total rainfall
    p++;             // Move pointer to the next year
  }

  printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);

  printf("MONTHLY AVERAGES:\n\n");
  printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

  for (int month = 0; month < MONTHS; month++) {
    subtot = 0; // Reset subtotal for each month
    p = rain;   // Reset pointer to the start of the array for each column
                // calculation
    for (int year = 0; year < YEARS; year++) {
      subtot += *(*p + month); // Access the month for each year
      p++;                     // Move pointer to the next year
    }
    printf("%4.1f ", subtot / YEARS);
  }
  printf("\n");

  return 0;
}
