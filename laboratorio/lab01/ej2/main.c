/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_file(int array[]) {

    FILE * pointer = stdin;
    unsigned int length;
    unsigned int cont;
    int value;

    cont = 0u;
    fscanf(pointer, "%u", &length);
    while (cont < length) {
        fscanf(pointer, "%d", &value); 
        array[cont] = value;
        cont++;
    }
    return length;
}

void array_dump(int a[], unsigned int length) {

    printf("[");
    unsigned int last;
    for (unsigned i = 0; i < length-1; i++)
    {
        printf("%d, ", a[i]);
        last = i;
    }
    printf("%d]\n", a[last + 1]);
    
}


int main() {
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
