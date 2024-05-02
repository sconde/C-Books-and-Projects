#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
  char data[MAX_SIZE];
  int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) { stack->top = -1; }

// Function to check if the stack is empty
int isEmpty(Stack *stack) { return stack->top == -1; }

// Function to check if the stack is full
int isFull(Stack *stack) { return stack->top == MAX_SIZE - 1; }

// Function to push an element onto the stack
void push(Stack *stack, char element) {
  if (isFull(stack)) {
    printf("Stack Overflow\n");
    exit(1);
  }
  stack->data[++stack->top] = element;
}

// Function to pop an element from the stack
char pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow\n");
    exit(1);
  }
  return stack->data[stack->top--];
}

int main() {
  Stack stack;
  initialize(&stack);

  char input[MAX_SIZE];
  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin);

  // Push characters onto the stack
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] != '\n') {
      push(&stack, input[i]);
    }
  }

  // Pop and display characters from the stack
  printf("Reversed string: ");
  while (!isEmpty(&stack)) {
    printf("%c", pop(&stack));
  }
  printf("\n");

  return 0;
}