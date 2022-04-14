#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {

    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

char *parse_filepath(int argc, char *argv[]) {
    char *result;
    if (argc < 2) {
        exit(EXIT_FAILURE);
    }
    result = argv[1];
    return result;
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size) {

    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        printf("ERROR: error leyendo el archivo");
    }
    unsigned int i = 0;
    while(!feof(file) && i <= max_size) {
        if (fscanf(file, "%u '%c'\n", &indexes[i], &letters[i]) != EOF) {
            i++;
        } 
    }

    fclose(file);
    return i;
    
}



int main(int argc, char *argv[]) {
    
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    char *filepath = parse_filepath(argc, argv);
    
    length = data_from_file(filepath, indexes, letters, MAX_SIZE);
    

    printf("Dump \n");
    printf("letters: \n");
    dump(letters, length);

    printf("sorted: \n");

    for (unsigned int i = 0; i < length; i++) {
        sorted[indexes[i]] = letters[i];
    }
    dump(sorted, length);

    return EXIT_SUCCESS;
}

