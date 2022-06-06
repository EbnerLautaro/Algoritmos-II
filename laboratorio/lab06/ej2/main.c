#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int main (void) {


    char *w1 = "Hi Mom!";
    char *w2 = "Hi Dad!";
    string str1 = string_create(w1);
    string str2 = string_create(w2);

    printf("a -> ");
    string_dump(str1, stdout);
    printf("b -> ");
    string_dump(str2, stdout);

    printf("a <= b -> %s\n", string_less(str1, str2) ? "True" : "False");
    printf("a == b -> %s\n", string_eq(str1, str2) ? "True" : "False");

    return EXIT_SUCCESS;
}