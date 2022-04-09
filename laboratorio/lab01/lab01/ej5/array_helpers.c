
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "mybool.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    
    FILE* filepointer = fopen(filepath, "r");
    if (filepointer == NULL)
    {
        printf("ERROR: error leyendo el archivo");
    }
    
    int value;
    unsigned int cont = 0u;
    unsigned int length = 0u;

    while (fscanf(filepointer, "%d ", &value) != EOF)
    {
        assert(length<=max_size);
        if (cont==0u) {
            length = value;
        }
        else 
        {
            array[cont-1] = value;
        }
        cont++;
    }
                             
    fclose(filepointer);
    return length;
}

void array_dump(int a[], unsigned int length) {

    printf("[");
    unsigned int last;
    for (unsigned i = 0u; i < length-1; i++)
    {
        printf("%d, ", a[i]);
        last = i;
    }
    printf("%d]\n", a[last + 1]);
}

mybool array_is_sorted(int a[], unsigned int length) {
    mybool res = true;
    for (unsigned int i = 0; i < length-1; i++)
    {
        if (a[i] > a[i+1])
        {
            res = false;
            break;
        }
    }
    return res;

}

