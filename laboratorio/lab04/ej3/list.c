#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

struct _node {
    elem value;
    struct _node * next;
};

list empty(void){ 
    list l = NULL;
    // l = malloc(sizeof(struct _node));
    return l;
}

list addl(list l, elem e) {
    list n;
    n = malloc(sizeof(struct _node));
    n->value = e;
    n->next = l;
    return n;
}

void destroy(list l) {
    free(l);
}

bool is_empty(list l) {
    return (l!=NULL);

}

elem head(list l) {
    assert(!is_empty(l));
    return l->value;
}

/*
list tail(list l) {
    assert(!is_empty(l));
    list n = NULL;
    list p = NULL;
    n = malloc(sizeof(struct _node));
    p = malloc(sizeof(struct _node));
    n = l;
    p = l;
    n = p->next;
    free(p);
    return n;
}
*/    
list tail(list l) {
    assert(!is_empty(l));
    return l->next;
}

list addr (list l, elem e) {
    list n = NULL;
    n = malloc(sizeof(struct _node));
    n->next = NULL;
    n->value = e;
    
    if (l == NULL) {
        l=n;
    } else {
        list i = l;
        //avanzo hasta el ultimo elemento
        while (i->next!=NULL) { 
            i = i->next;
        }
        // el proximo del que antes era ultimo es el nuevo elemento
        i->next=n;
    }
    return l;
}


list drop(list l, unsigned int n) {
    list s = l;
    for (unsigned int i = 0; i < n; i++)
    {
        s = s->next;
    }
    return s;
}

elem list_index(list l, unsigned int n) {
    assert(n < length(l));
    list s = l;
    for (unsigned int i = 0; i < n; i++)
    {
        s = s->next;
    }
    return s->value;
}

list concat(list l1, list l2) {
    list n = l1;
    while (n->next != NULL) {
        n = n->next;
    }
    n->next = l2;
    return n;
}

list copy_list(list l) {
    list n = NULL;
    n = malloc(sizeof (struct _node));
    list s = n;
    for (unsigned int i = 0; i < length(l); i++)
    {
        n->value = list_index(l,i);
        n = n->next;
        n = malloc(sizeof (struct _node));
    }
    return s;
}

unsigned int length(list l) {
    unsigned int res = 0;
    list n = l;
    while(n!=NULL) {
        n = n->next;
        res++; 
    }
    return res;
}