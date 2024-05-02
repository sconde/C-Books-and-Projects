#include <stdio.h>

#define FONT_ID_MASK 0xFF      // Font ID: 8 bits (0-255)
#define FONT_SIZE_MASK 0x7F00  // Font Size: 7 bits (0-127)
#define ALIGNMENT_MASK 0x18000 // Alignment: 2 bits (0-2)
#define BOLD_MASK 0x20000      // Bold: 1 bit
#define ITALIC_MASK 0x40000    // Italic: 1 bit
#define UNDERLINE_MASK 0x80000 // Underline: 1 bit

#define FONT_ID_SHIFT 0
#define FONT_SIZE_SHIFT 8
#define ALIGNMENT_SHIFT 15
#define BOLD_SHIFT 17
#define ITALIC_SHIFT 18
#define UNDERLINE_SHIFT 19

const char *alignments[3] = {"left", "center", "right"};

void displayFont(unsigned long font) {
  printf("ID SIZE ALIGNMENT B I U\n");
  printf("%lu  %lu    %s    %s  %s  %s\n",
         (font & FONT_ID_MASK) >> FONT_ID_SHIFT,
         (font & FONT_SIZE_MASK) >> FONT_SIZE_SHIFT,
         alignments[(font & ALIGNMENT_MASK) >> ALIGNMENT_SHIFT],
         (font & BOLD_MASK) ? "on" : "off", (font & ITALIC_MASK) ? "on" : "off",
         (font & UNDERLINE_MASK) ? "on" : "off");
}

void changeFontSettings(unsigned long *font) {
  char option;
  unsigned long temp;

  do {
    displayFont(*font);
    printf("f)change font s)change size a)change alignment\n");
    printf("b)toggle bold i)toggle italic u)toggle underline\n");
    printf("q)quit\n");
    scanf(" %c", &option);

    switch (option) {
    case 'f':
      printf("Enter font ID (0-255): ");
      scanf("%lu", &temp);
      *font = (*font & ~FONT_ID_MASK) | (temp << FONT_ID_SHIFT);
      break;
    case 's':
      printf("Enter font size (0-127): ");
      scanf("%lu", &temp);
      *font = (*font & ~FONT_SIZE_MASK) | (temp << FONT_SIZE_SHIFT);
      break;
    case 'a':
      printf("Select alignment:\n1)left c)center r)right\n");
      char align;
      scanf(" %c", &align);
      temp = (align == '1' ? 0 : align == 'c' ? 1 : 2);
      *font = (*font & ~ALIGNMENT_MASK) | (temp << ALIGNMENT_SHIFT);
      break;
    case 'b':
      *font ^= BOLD_MASK;
      break;
    case 'i':
      *font ^= ITALIC_MASK;
      break;
    case 'u':
      *font ^= UNDERLINE_MASK;
      break;
    case 'q':
      printf("Bye!\n");
      return;
    default:
      printf("Invalid choice.\n");
    }
  } while (option != 'q');
}

int main() {
  unsigned long myFont = 0x000001C2; // Example initial settings: ID 1, Size 12,
                                     // Alignment 0 (left), all styles off
  changeFontSettings(&myFont);
  return 0;
}
