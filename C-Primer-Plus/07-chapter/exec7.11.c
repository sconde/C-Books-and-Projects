#include <stdio.h>

#define PRICE_ARTICHOKE 2.05
#define PRICE_BEET 1.15
#define PRICE_CARROT 1.09
#define DISCOUNT_RATE 0.05
#define SHIPPING_THRESHOLD1 5
#define SHIPPING_THRESHOLD2 20
#define SHIPPING_COST1 6.50
#define SHIPPING_COST2 14.00
#define SHIPPING_COST_EXTRA 0.50

void display_menu();
double calculate_cost(double pounds, double price);
double calculate_discount(double total_cost);
double calculate_shipping(double total_pounds);

int main() {
  char choice;
  double pounds_artichokes = 0, pounds_beets = 0, pounds_carrots = 0;
  double cost_artichokes, cost_beets, cost_carrots, total_cost, discount,
      shipping, grand_total;

  while (1) {
    display_menu();
    printf("Enter your choice (a, b, c, q): ");
    scanf(" %c", &choice); // Note the space before %c to skip any newline
                           // characters left in the input buffer

    switch (choice) {
    case 'a':
      printf("Enter the pounds of artichokes: ");
      scanf("%lf", &pounds_artichokes);
      break;
    case 'b':
      printf("Enter the pounds of beets: ");
      scanf("%lf", &pounds_beets);
      break;
    case 'c':
      printf("Enter the pounds of carrots: ");
      scanf("%lf", &pounds_carrots);
      break;
    case 'q':
      goto calculate; // Exit the input loop
    default:
      printf("Invalid choice. Please enter a, b, c, or q.\n");
      continue;
    }
  }

calculate:
  cost_artichokes = calculate_cost(pounds_artichokes, PRICE_ARTICHOKE);
  cost_beets = calculate_cost(pounds_beets, PRICE_BEET);
  cost_carrots = calculate_cost(pounds_carrots, PRICE_CARROT);
  total_cost = cost_artichokes + cost_beets + cost_carrots;

  discount = calculate_discount(total_cost);
  double total_pounds = pounds_artichokes + pounds_beets + pounds_carrots;
  shipping = calculate_shipping(total_pounds);
  grand_total = total_cost - discount + shipping;

  printf("\nOrder summary:\n");
  printf("Artichokes: %.2f lbs at $%.2f per lb, cost: $%.2f\n",
         pounds_artichokes, PRICE_ARTICHOKE, cost_artichokes);
  printf("Beets: %.2f lbs at $%.2f per lb, cost: $%.2f\n", pounds_beets,
         PRICE_BEET, cost_beets);
  printf("Carrots: %.2f lbs at $%.2f per lb, cost: $%.2f\n", pounds_carrots,
         PRICE_CARROT, cost_carrots);
  printf("Total cost of vegetables: $%.2f\n", total_cost);
  printf("Discount: -$%.2f\n", discount);
  printf("Shipping: $%.2f\n", shipping);
  printf("Grand total: $%.2f\n", grand_total);

  return 0;
}

void display_menu() {
  printf("\nAvailable options:\n");
  printf("a) Add artichokes\n");
  printf("b) Add beets\n");
  printf("c) Add carrots\n");
  printf("q) Quit and calculate total\n");
}

double calculate_cost(double pounds, double price) { return pounds * price; }

double calculate_discount(double total_cost) {
  if (total_cost >= 100) {
    return total_cost * DISCOUNT_RATE;
  }
  return 0;
}

double calculate_shipping(double total_pounds) {
  if (total_pounds == 0) {
    return 0; // No shipping cost if no items are ordered
  } else if (total_pounds <= SHIPPING_THRESHOLD1) {
    return SHIPPING_COST1;
  } else if (total_pounds < SHIPPING_THRESHOLD2) {
    return SHIPPING_COST2;
  } else {
    return SHIPPING_COST2 +
           SHIPPING_COST_EXTRA * (total_pounds - SHIPPING_THRESHOLD2);
  }
}
