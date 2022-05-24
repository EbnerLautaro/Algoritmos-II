#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#include <stdio.h>
struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty() {
    stack s = (stack) malloc(sizeof(struct _s_stack));
    s->capacity = 1;
    s->size = 0;
    s->elems = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {
    assert (s!=NULL);
    if (s->size >= s->capacity || s->size == 0) { 
        // a s->elems le tengo que asignar el doble de memoria (el doble de capacidad) 
        s->elems = realloc(s->elems, 2 * s->capacity  * sizeof(stack_elem));
    } 
    s->elems[s->size] = e;
    (s->size)++; 
    return s;
}



stack stack_pop(stack s) {

    assert(!stack_is_empty(s));
    for (unsigned int i = 1; i < s->size; i++)
    {
        s->elems[i-1] = s->elems[i]; 
    }
    
    (s->size)--;
    return s;
}


unsigned int stack_size(stack s) {
    assert(!stack_is_empty(s));
    return s->size;
}


stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    return s->elems[0];
}

bool stack_is_empty(stack s) {
    return (s->size == 0);
}

stack_elem * stack_to_array(stack s) {
    assert(!stack_is_empty(s));
    return s->elems;
}

stack stack_destroy(stack s) {
    free(s->elems);
    free(s);
    return s;
}
