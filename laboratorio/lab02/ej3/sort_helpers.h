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

#endif
