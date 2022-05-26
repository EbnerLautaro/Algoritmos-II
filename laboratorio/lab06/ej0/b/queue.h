#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef struct s_queue * queue;

typedef int queue_elem;

/*
 * DESC: Creates a new instance of queue
 *
 * PRE: {true}
 *  q = queue_empty();
 * POS: {q --> queue && queue_is_empty(q)}
 *
 */
queue queue_empty(void);

/*
 * DESC: Adds element 'e' to the queue 'q'
 *
 * PRE: {q --> queue}
 *  q = queue_enqueue(q, e);
 * POS: {q --> queue && !queue_is_empty()}
 *
 */
queue queue_enqueue(queue q, queue_elem e);

/*
 * DESC: Indicates whether the queue 'q' is empty or not
 *
 */
bool queue_is_empty(queue q);

/*
 * DESC: Return the number of elements inside the queue 'q'
 *
 */
unsigned int queue_size(queue q);

/*
 * DESC: Return the first element of the queue 'q'
 *
 * PRE: {q --> queue && !queue_is_empty(q)}
 *  e = queue_first(q);
 * POS: {q --> queue}
 */
queue_elem queue_first(queue q);

/*
 * DESC: Remove the first element of the queue 'q'
 *
 * PRE: {q --> queue && !queue_is_empty(q)}
 *  q = queue_dequeue(q);
 * POS: {q --> queue}
 *
 */
queue queue_dequeue(queue q);

/*
 * DESC: Destroy instance of queue, freeing all memory used by 'q'.
 *
 * PRE: {q --> queue}
 *  q = queue_destroy(q);
 * POS: {q == NULL}
 *
 */
queue queue_destroy(queue q);

#endif
