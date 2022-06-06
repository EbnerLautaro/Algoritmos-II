#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    unsigned int size;
    struct s_node * front;
};

struct s_node {
    pqueue_elem elem;
    unsigned int priority;           
    struct s_node * next;
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    new_node->elem = e; 
    new_node->priority = priority; 
    new_node->next = NULL; 
    assert(new_node!=NULL);
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pqueue q) {
    bool res = false;
    if (q!=NULL) {
        res = true;
        if (q->front != NULL) {
            struct s_node *pointer = q->front;
            while (res && pointer->next != NULL ) {
                if (pointer->priority >= pointer->next->priority) {
                    pointer = pointer->next;
                } else {
                    res = false;
                }         
            }
        }
    }
    return res;
}

pqueue pqueue_empty(void) {
    pqueue q =malloc(sizeof(struct s_pqueue));
    q->front = NULL;
    q->size = 0U;
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    struct s_node *current = q->front;       
    struct s_node *past = NULL;  
    if (!pqueue_is_empty(q)) {
        if (new_node->priority > current->priority ) {
            new_node->next = current;
            q->front = new_node;
            
        } else {
            while (current != NULL && new_node->priority <= current->priority ) {
                past = current;
                current = current->next;
            }
            new_node->next = current;
            past->next = new_node;
        }

    } else {
        q->front = new_node;
    } 
    q->size++;
    assert(invrep(q) && !pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));
    return (q->front==NULL);
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->elem;
}

unsigned int pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->priority;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    return q->size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node * pointer = q->front->next;
    free(q->front);
    q->front = pointer;   
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    struct s_node * n = q->front;

    while(q->front != NULL) {
        n = n->next;
        destroy_node(q->front);
        q->front = n;
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}
