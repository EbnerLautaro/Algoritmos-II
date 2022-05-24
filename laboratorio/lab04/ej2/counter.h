#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

/* counter as a pointer to structs to guarantee encapsulation */
typedef struct _counter * counter;


/* Constructors */

/*
    Create a new counter with initial value. Allocates new memory.
    Being c the returned counter, counter_is_init(c) should be true.
*/
counter counter_init(void);

/*
    Increments the counter c.
*/
void counter_inc(counter c);


/* Operations */

/*
    Return whether the counter c has the initial value.
*/
bool counter_is_init(counter c);

/*
    Decrements the counter c.
    PRECONDITION: !counter_is_init(c)
*/
void counter_dec(counter c);

/*
    Makes a copy of counter c. Allocates new memory.
*/
counter counter_copy(counter c);

/*
   Frees memory for c.
*/
void counter_destroy(counter c);

#endif
