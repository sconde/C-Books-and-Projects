#include "list.h"
#include <stdlib.h>

// Initialize the list
void InitializeList(List *plist) {
  plist->head = NULL;
  plist->end = NULL;
}

// Check if the list is empty
bool ListIsEmpty(const List *plist) { return plist->head == NULL; }

// Check if the list is full
bool ListIsFull(const List *plist) {
  Node *pt;
  bool full;
  pt = (Node *)malloc(sizeof(Node));
  if (pt == NULL)
    full = true;
  else
    full = false;
  free(pt);
  return full;
}

// Count the number of items in the list
unsigned int ListItemCount(const List *plist) {
  unsigned int count = 0;
  Node *pnode = plist->head;
  while (pnode != NULL) {
    ++count;
    pnode = pnode->next;
  }
  return count;
}

// Add item to end of list
bool AddItem(List *plist, void *item) {
  Node *pnew = (Node *)malloc(sizeof(Node));
  if (pnew == NULL)
    return false;

  pnew->item = item;
  pnew->next = NULL;

  if (ListIsEmpty(plist))
    plist->head = pnew; // empty list, so place at head
  else
    plist->end->next = pnew; // else place at end

  plist->end = pnew; // adjust end to new node
  return true;
}

// Traverse the list
void Traverse(const List *plist, void (*pfun)(void *item)) {
  Node *pnode = plist->head;
  while (pnode != NULL) {
    (*pfun)(pnode->item);
    pnode = pnode->next;
  }
}

// Empty the list
void EmptyTheList(List *plist) {
  Node *psave;
  while (plist->head != NULL) {
    psave = plist->head->next;
    free(plist->head);
    plist->head = psave;
  }
  plist->end = NULL;
}
