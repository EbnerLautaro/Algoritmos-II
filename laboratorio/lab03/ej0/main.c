#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

// static void dump(char a[], unsigned int length) {
//     printf("\"");
//     for (unsigned int j=0u; j < length; j++) {
//         printf("%c", a[j]);
//     }
//     printf("\"");
//     printf("\n\n");
// }

char *parse_filepath(int argc, char *argv[]) {
    char *result;
    // thegeekstuff.com/2013/01/c-argc-argv/

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];
    return result;
}



int main(int argc, char *argv[]) {
    FILE *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    char *filepath = NULL;
    filepath = parse_filepath(argc, argv);

    printf(filepath);

    // dump(sorted, length);

    return EXIT_SUCCESS;
}

