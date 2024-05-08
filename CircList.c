#include "CircList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


struct _node {
    int val;
    struct _node* next;
};

struct _list {
    struct _node* begin;
    int qty;
};

CircList* CircList_createList() {
    CircList* list = (CircList*)malloc(sizeof(CircList));
    if (list == NULL) 
        return NULL;

    list->begin = NULL;
    list->qty = 0;

    return list;
}

Node* Node_create(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) 
        return NULL;

    node->val = val;
    node->next = NULL;

    return node;
}

bool CircList_insert(CircList *list, int val) {
    Node *no = Node_create(val);

    if (list->begin == NULL) {
        list->begin = no;
        no->next = no;
    } else {
        Node *aux = list->begin;
        while (aux->next != list->begin) {
            aux = aux->next;
        }
        aux->next = no;
        no->next = list->begin;
    }
    list->qty++;
    return true;
}

int Exercito_edmundo(CircList *list, int m) {

    Node *current = list->begin;
    Node *aux = NULL;    
    do {
        int i;
        for (i = 0; i < m; i++) {
            aux = current;
            current = aux->next;
        }
        CircList_remove(list, current->val);
        current = aux->next;  

    } while(list->qty != 1);

    return current->val;
}

//remove
bool CircList_remove(CircList *list, int val) {
    if (list->begin == NULL) {
        return false;
    }

    Node *aux = list->begin;
    Node *aux2 = NULL;

    while (aux->val != val) {
        if (aux->next == list->begin) {
            return false;
        }
        aux2 = aux;
        aux = aux->next;
    }

    if (aux == list->begin) {
        if (aux->next == list->begin) {
            list->begin = NULL;
        } else {
            aux2 = list->begin;
            while (aux2->next != list->begin) {
                aux2 = aux2->next;
            }
            list->begin = aux->next;
            aux2->next = list->begin;
        }
    } else if (aux->next == list->begin) {
        aux2->next = list->begin;
    } else {
        aux2->next = aux->next;
    }

    free(aux);
    list->qty--;
    return true;
}

void CircList_print(CircList *list) {

    if (list->begin != NULL) {
        Node *aux = list->begin;
        while (aux->next != list->begin) {
            printf("%d->", aux->val);
            aux = aux->next;
        }
        printf("%d\n", aux->val);
    }
}