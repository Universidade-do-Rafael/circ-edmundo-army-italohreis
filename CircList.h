#ifndef CIRC_LIST_H
#define CIRC_LIST_H
#include <stdbool.h>

typedef struct _list CircList;

typedef struct _node Node;

CircList* CircList_createList();

Node* Node_create(int data);

bool CircList_insert(CircList* list, int data);

void CircList_print(CircList* list);

int Exercito_raimundo(CircList* list, int m);

bool CircList_remove(CircList* list, int data);

#endif