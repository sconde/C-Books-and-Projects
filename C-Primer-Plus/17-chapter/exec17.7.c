#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char word[100];
  int count;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(char *word) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->word, word);
  newNode->count = 1;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insertNode(Node *root, char *word) {
  if (root == NULL) {
    return createNode(word);
  }

  int cmp = strcmp(word, root->word);
  if (cmp < 0) {
    root->left = insertNode(root->left, word);
  } else if (cmp > 0) {
    root->right = insertNode(root->right, word);
  } else {
    root->count++;
  }

  return root;
}

void inorderTraversal(Node *root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%s: %d\n", root->word, root->count);
    inorderTraversal(root->right);
  }
}

Node *searchNode(Node *root, char *word) {
  if (root == NULL || strcmp(word, root->word) == 0) {
    return root;
  }

  if (strcmp(word, root->word) < 0) {
    return searchNode(root->left, word);
  } else {
    return searchNode(root->right, word);
  }
}

void printOccurrences(Node *root, char *word) {
  Node *node = searchNode(root, word);
  if (node != NULL) {
    printf("%s occurred %d times.\n", node->word, node->count);
  } else {
    printf("%s does not exist in the file.\n", word);
  }
}

void freeTree(Node *root) {
  if (root != NULL) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

int main() {
  FILE *file = fopen("textfile.txt", "r");
  if (file == NULL) {
    printf("Failed to open the file.\n");
    return 1;
  }

  Node *root = NULL;
  char word[100];

  while (fscanf(file, "%s", word) != EOF) {
    root = insertNode(root, word);
  }

  fclose(file);

  int choice;
  char searchWord[100];

  do {
    printf("Menu:\n");
    printf("1. List all words and occurrences\n");
    printf("2. Search for a word\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      inorderTraversal(root);
      break;
    case 2:
      printf("Enter a word to search: ");
      scanf("%s", searchWord);
      printOccurrences(root, searchWord);
      break;
    case 3:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 3);

  freeTree(root);

  return 0;
}