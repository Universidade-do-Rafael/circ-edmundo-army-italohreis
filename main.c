#include <stdio.h>
#include "CircList.h"

int main() {

    int n, m;

    CircList* list = CircList_createList();
    scanf("%d", &n);
    scanf("%d", &m);

    int i;
    for (i = 0; i < n; i++) {
        CircList_insert(list, i+1);
    }    
    
    printf("%d\n", Exercito_raimundo(list, m));
    
    return 0;
}