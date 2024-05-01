#include <stdio.h>

int main() {
  int friends = 5;
  int week = 1;

  while (friends <= 150) {
    int friends_dropped = week;
    friends -= friends_dropped;
    friends *= 2;

    printf("Week %d: %d friends\n", week, friends);

    week++;
  }

  return 0;
}