#include <stdio.h>

typedef struct {
  unsigned int fontID : 8;   // 8 bits for font ID
  unsigned int fontSize : 7; // 7 bits for font size
  unsigned int
      alignment : 2;       // 2 bits for alignment (0-left, 1-center, 2-right)
  unsigned int bold : 1;   // 1 bit for bold
  unsigned int italic : 1; // 1 bit for italic
  unsigned int underline : 1; // 1 bit for underline
} Font;

const char *alignments[3] = {"left", "center", "right"};

void displayFont(const Font *font) {
  printf("ID SIZE ALIGNMENT B I U\n");
  printf("%d  %d    %s    %s  %s  %s\n", font->fontID, font->fontSize,
         alignments[font->alignment], font->bold ? "on" : "off",
         font->italic ? "on" : "off", font->underline ? "on" : "off");
}

void changeFontSettings(Font *font) {
  char option;
  unsigned int temp; // Temporary variable for input

  do {
    displayFont(font);
    printf("f)change font s)change size a)change alignment\n");
    printf("b)toggle bold i)toggle italic u)toggle underline\n");
    printf("q)quit\n");
    scanf(" %c",
          &option); // note the space before %c to skip any newline characters

    switch (option) {
    case 'f':
      printf("Enter font ID (0-255): ");
      scanf("%u", &temp);
      font->fontID = temp; // Assign the temporary variable to the bit-field
      break;
    case 's':
      printf("Enter font size (0-127): ");
      scanf("%u", &temp);
      font->fontSize = temp; // Assign the temporary variable to the bit-field
      break;
    case 'a':
      printf("Select alignment:\n1)left c)center r)right\n");
      char align;
      scanf(" %c", &align);
      if (align == '1')
        font->alignment = 0;
      else if (align == 'c')
        font->alignment = 1;
      else if (align == 'r')
        font->alignment = 2;
      break;
    case 'b':
      font->bold = !font->bold;
      break;
    case 'i':
      font->italic = !font->italic;
      break;
    case 'u':
      font->underline = !font->underline;
      break;
    case 'q':
      printf("Bye!\n");
      break;
    default:
      printf("Invalid choice.\n");
    }
  } while (option != 'q');
}

int main() {
  Font myFont = {1, 12, 0, 0, 0, 0}; // Example initial settings
  changeFontSettings(&myFont);
  return 0;
}
