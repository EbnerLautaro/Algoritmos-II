#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

struct s_pstack {
    struct s_node *front;
    unsigned int size;
};

struct s_node {
    pstack_elem elem;
    priority_t priority;
    struct s_node *next;
};

static struct s_node * create_node(pstack_elem e, priority_t priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pstack s) {
    struct s_node *n = s->front;
    bool res = true;
    if (n != NULL) {
        while (n->next != NULL && res) {
            res = (n->priority >= n->next->priority);
            n = n->next;
        }
    }
    return res;
}

pstack pstack_empty(void) {
    pstack s=NULL;
    s = malloc(sizeof(struct s_pstack));
    s->front = NULL;
    s->size = 0u;
    assert(invrep(s) && pstack_is_empty(s));
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    struct s_node *new_node = create_node(e, priority);
    struct s_node *current = s->front;       
    struct s_node *past = NULL;    
    if (!pstack_is_empty(s)) {
        if (new_node->priority >= current->priority) {      // caso que sea el de mayor prioridad
            new_node->next = current;
            s->front = new_node;
        } else {                                            // minimo es el segundo (past != NULL)
            while (current != NULL && new_node->priority < current->priority){
                past = current;
                current = current->next;
            }
            new_node->next = current;
            past->next = new_node;
        }
    } else {                                               // caso donde s es vacio
        s->front = new_node;
    }
    s->size++;
    assert(invrep(s) && !pstack_is_empty(s));
    return s;
}

bool pstack_is_empty(pstack s) {
    // tambien puede ser igualando el size a 0;
    return (s->size == 0);
}

pstack_elem pstack_top(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    return s->front->elem;
}

priority_t pstack_top_priority(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    return s->front->priority;
}

unsigned int pstack_size(pstack s) {
    assert(invrep(s));
    return s->size;
}

pstack pstack_pop(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    struct s_node * n = s->front->next;
    free(s->front);
    s->front = n;
    s->size--;
    assert(invrep(s));
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    struct s_node *n = s->front;
    while (s->front != NULL) {
        s->front = n->next;
        destroy_node(n);
        n = s->front;
    }
    free(s);
    s = NULL;
    assert(s == NULL);
    return s;
}

