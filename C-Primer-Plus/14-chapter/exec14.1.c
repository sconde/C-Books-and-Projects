#include <stdio.h>
#include <string.h>

int days_in_months(const char *month, int year) {
  const char *months[] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    days[1] = 29; // February in a leap year
  }

  int total_days = 0;
  for (int i = 0; i < 12; i++) {
    total_days += days[i];
    if (strcmp(months[i], month) == 0) {
      break;
    }
  }
  return total_days;
}

int main() {
  char month[20];
  int year;
  printf("Enter the month and year (e.g., March 2024): ");
  scanf("%s %d", month, &year);

  printf("Total days up to %s %d: %d\n", month, year,
         days_in_months(month, year));

  return 0;
}
