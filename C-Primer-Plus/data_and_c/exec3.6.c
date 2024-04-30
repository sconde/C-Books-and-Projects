#include <stdio.h>

int main() {
  double massPerMolecule = 3.0e-23; // Mass of a single water molecule in grams
  double massPerQuart = 950.0;      // Mass of a quart of water in grams
  // Calculate the number of water molecules in a quart
  double moleculesPerQuart = massPerQuart / massPerMolecule;

  double quarts;
  printf("Enter the amount of water in quarts: ");
  scanf("%lf", &quarts);

  double totalMolecules = quarts * moleculesPerQuart;
  printf("The number of water molecules in %.2lf quarts is %.2lf\n", quarts,
         totalMolecules);

  return 0;
}