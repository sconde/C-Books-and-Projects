#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_leap_year(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return 1;
  }
  return 0;
}

int get_month_number(const char *month) {
  const char *months[] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};
  const char *abbreviations[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  for (int i = 0; i < 12; i++) {
    if (strcasecmp(month, months[i]) == 0 ||
        strcasecmp(month, abbreviations[i]) == 0) {
      return i + 1; // Month numbers are 1-based
    }
  }

  // Check if month is numeric
  int month_num = atoi(month);
  if (month_num >= 1 && month_num <= 12) {
    return month_num;
  }

  return -1; // Invalid month
}

int days_up_to_date(int day, const char *month_input, int year) {
  int month_number = get_month_number(month_input);
  if (month_number == -1) {
    printf("Invalid month entry.\n");
    return -1;
  }

  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (is_leap_year(year)) {
    days_in_month[1] = 29; // Adjust February for leap year
  }

  int total_days = 0;
  for (int i = 0; i < month_number - 1; i++) {
    total_days += days_in_month[i];
  }
  total_days += day;

  return total_days;
}

int main() {
  char month_input[20];
  int day, year;

  printf("Enter the day, month, and year (e.g., 23 March 2024 or 23 3 2024): ");
  scanf("%d %s %d", &day, month_input, &year);

  int total_days = days_up_to_date(day, month_input, year);
  if (total_days != -1) {
    printf("Total days up to %d %s %d: %d\n", day, month_input, year,
           total_days);
  }

  return 0;
}
