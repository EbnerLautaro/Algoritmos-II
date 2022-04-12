#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


/* Permutes elements of a[izq..der] and returns pivot such that:
    - izq <= pivot <= der
    - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
    - a[pivot] 'goes_before' all the elements in a(pivot,der]
*/
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    
    unsigned int pivot = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while (j >= i) {
        if (goes_before(a[i],a[pivot])) {
            i ++;   
        } else if (goes_before(a[pivot],a[j]) ){
            j --;   
        } else {    
            swap(a, i,j);
        }
    }
    swap(a, pivot, j);
    pivot = j;
    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    
    unsigned int pivot;
    if (der > izq) {
        pivot = partition(a,izq,der);
        quick_sort_rec(a, izq, pivot);
        quick_sort_rec(a, pivot+1, der);
    }
   
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

