#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 169, 34};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", 
           sizeof(messi.name),
           sizeof(messi.age),
           sizeof(messi.height),
           sizeof(messi));


    /*  
        La respuesta es 40, porque tiene que "redondear" al "default alignment" el cual es probablemente 4
        https://stackoverflow.com/a/1841938      
        https://stackoverflow.com/a/119134       *mejor explicacion*
        http://www.c-faq.com/struct/align.html   
    */

    return EXIT_SUCCESS;
}

