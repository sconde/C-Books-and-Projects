#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Function to find the second string within the first string
char *string_in(const char *s1, const char *s2) {
  if (*s2 == '\0') // If s2 is empty, return NULL
    return NULL;

  for (; *s1 != '\0'; s1++) {
    const char *p1 = s1;
    const char *p2 = s2;

    // Compare string s2 with the substring of s1
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
      p1++;
      p2++;
    }

    // If the whole of s2 has been matched
    if (*p2 == '\0') {
      return (char *)s1;
    }
  }

  return NULL; // s2 not found in s1
}

int main() {
  char str1[100];
  char str2[100];
  char *found;

  while (1) {
    printf("Enter the main string (or 'quit' to exit): ");
    fgets(str1, sizeof(str1), stdin);
    if (strncmp(str1, "quit\n", 5) == 0) {
      break;
    }

    // Remove the newline character
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the substring to find: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove the newline character

    found = string_in(str1, str2);
    if (found != NULL) {
      printf("Substring found at position: %ld\n", found - str1);
    } else {
      printf("Substring not found.\n");
    }
  }

  return 0;
}
