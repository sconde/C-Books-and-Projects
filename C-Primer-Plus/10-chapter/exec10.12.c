#include <stdio.h>

#define MONTHS 12 // Number of months in a year
#define YEARS 5   // Number of years of data

// Function prototypes
void calculate_yearly_totals(const float rain[][MONTHS], int years);
void calculate_monthly_averages(const float rain[][MONTHS], int years);
void display_header();

// Function to calculate and display yearly totals and averages
void calculate_yearly_totals(const float rain[][MONTHS], int years) {
  float total = 0.0;
  printf(" YEAR     RAINFALL  (inches)\n");
  for (int year = 0; year < years; year++) {
    float subtot = 0.0;
    for (int month = 0; month < MONTHS; month++) {
      subtot += rain[year][month];
    }
    printf("%5d %15.1f\n", 2010 + year, subtot);
    total += subtot;
  }
  printf("\nThe yearly average is %.1f inches.\n\n", total / years);
}

// Function to calculate and display monthly averages
void calculate_monthly_averages(const float rain[][MONTHS], int years) {
  printf("MONTHLY AVERAGES:\n\n");
  printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");

  for (int month = 0; month < MONTHS; month++) {
    float subtot = 0;
    for (int year = 0; year < years; year++) {
      subtot += rain[year][month];
    }
    printf("%4.1f ", subtot / years);
  }
  printf("\n");
}

// Function to display the headers
void display_header() {
  printf("This program calculates the rainfall statistics.\n\n");
}

// Main function
int main(void) {
  const float rain[YEARS][MONTHS] = {
      {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
      {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 3.0, 0.9, 1.4, 7.3},
      {9.1, 5.8, 5.6, 7.4, 3.2, 1.0, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1},
      {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
      {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}};

  display_header();
  calculate_yearly_totals(rain, YEARS);
  calculate_monthly_averages(rain, YEARS);

  return 0;
}
