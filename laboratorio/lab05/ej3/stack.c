#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    struct _s_stack *next;
};


stack stack_empty(void) {
    stack s = NULL;
    return s;
}


stack stack_push(stack s, stack_elem e) {
    stack j = malloc(sizeof(struct _s_stack));
    j->elem = e;
    j->next = s;
    return j;
}


stack stack_pop(stack s) {
    stack n = s;
    s = s->next;
    n->next = NULL;
    free(n);
    return s;
}


unsigned int stack_size(stack s) {
    stack n = s;
    unsigned int size = 0u;

    while (n!=NULL)
    {
        n = n->next;
        size++;
    }
    return size;
}


stack_elem stack_top(stack s) {
    assert(s != NULL);
    return s->elem;
}


bool stack_is_empty(stack s) {
    return (s==NULL);
}


stack_elem *stack_to_array(stack s) {

    stack pointer = s;
    unsigned int length = stack_size(s); 
    stack_elem * array = malloc(sizeof(stack_elem) * length);
    for (int i = length-1; i >= 0; i--)
    {
        array[i] = pointer->elem;
        pointer = pointer->next;
    }
    return array;
}


stack stack_destroy(stack s) {
    stack n = s;

    while (s!=NULL){
        s=s->next;
        free(n);
        n=s;
    }
    free(n);
    return n;

}
