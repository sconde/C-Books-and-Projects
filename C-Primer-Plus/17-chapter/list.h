#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node {
  void *item;
  struct node *next;
} Node;

typedef struct list {
  Node *head;
  Node *end;
} List;

// Function prototypes
void InitializeList(List *plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
bool AddItem(List *plist, void *item);
void Traverse(const List *plist, void (*pfun)(void *item));
void EmptyTheList(List *plist);

#endif
