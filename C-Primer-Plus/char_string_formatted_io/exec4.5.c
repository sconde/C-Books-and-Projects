#include <stdio.h>

int main() {
  float downloadSpeed, fileSize, downloadTime;

  printf("Enter the download speed in megabits per second (Mbs): ");
  scanf("%f", &downloadSpeed);

  printf("Enter the size of the file in megabytes (MB): ");
  scanf("%f", &fileSize);

  downloadTime = (fileSize * 8) / downloadSpeed;

  printf("At %.2f megabits per second, a file of %.2f megabytes downloads in "
         "%.2f seconds.\n",
         downloadSpeed, fileSize, downloadTime);

  return 0;
}