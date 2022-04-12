#ifndef _SORT_HELPERS_H
#define _SORT_HELPERS_H

#include <stdbool.h>

/* Abstract total order for sorting algorithms */
bool goes_before(int x, int y);

/* Checks if the array 'a' is in ascending order */
bool array_is_sorted(int a[], unsigned int length);

/* Exchanges elements of array 'a' in the given positions 'i' and 'j'
   Array remains the same if the two positions are the same
*/
void swap(int a[], unsigned int i, unsigned int j);

/* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
*/
unsigned int partition(int a[], unsigned int izq, unsigned int der);

#endif
