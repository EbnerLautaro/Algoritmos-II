#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    struct _s_stack *next;
    unsigned int index;
};


stack stack_empty(void) {
    stack s = NULL;
    return s;
}


stack stack_push(stack s, stack_elem e) {
    stack j = malloc(sizeof(struct _s_stack));
    j->elem = e;
    j->next = s;
    if (s == NULL) {
        j->index = 0;
    } else {
        j->index = s->index+1;
    }
    return j;
}


stack stack_pop(stack s) {
    stack n = s;
    s = s->next;
    free(n);
    return s;
}


unsigned int stack_size(stack s) {
    return s->index+1;
}


stack_elem stack_top(stack s) {
    return s->elem;
}


bool stack_is_empty(stack s) {
    return (s==NULL);
}


stack_elem *stack_to_array(stack s) {
    unsigned int length =stack_size(s); 
    stack_elem * array = malloc(sizeof(struct _s_stack) * length);

    for (unsigned int i = length-1; i <= 0; i--)
    {
        array[i] = stack_top(s);
        s = stack_pop(s);
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
