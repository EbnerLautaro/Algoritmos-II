#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef int elem;
typedef struct _node * list;

// Constructors

// crea una lista vacía.
list empty(void);

// agrega el elemento e al comienzo de la lista l.
list addl(list l, elem e);

// Operations

// Libera memoria en caso que sea necesario.
void destroy(list l);


// Is the list empty? 
bool is_empty(list l);


// Devuelve el primer elemento de la lista l
// PRE: not is_empty(l)
elem head(list l);

// Elimina el primer elemento de la lista l
// PRE: not is_empty(l)
list tail(list l);

// agrega el elemento e al final de la lista l.
list addr(list l, elem e);

// // Devuelve la cantidad de elementos de la lista l
unsigned int length(list l);

// // Devuelveuna copia de la lista l
list copy_list(list l);

// // Elimina los primeros n elementos de l
list drop(list l, unsigned int n); 

// // Deja en l sólo los primeros n elementos, eliminando el resto
list take(list l, unsigned int n);

// // Devuelve el n-ésimo elemento de la lista l
// // PRE: length(l) > n
elem list_index(list l, unsigned int n);
// elem index(list l, unsigned int n);

// // Agrega al final de l1 todos los elementos de l2
list concat(list l1, list l2);

#endif
