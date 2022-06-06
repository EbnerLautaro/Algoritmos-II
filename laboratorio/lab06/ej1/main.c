/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];
    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /*dumping the tree*/
    abb_dump(tree);
    if (!abb_is_empty(tree)) {
        printf("\n");
        printf("- Raiz -> %d\n- Minimo -> %d\n- Maximo -> %d\n", abb_root(tree), abb_min(tree), abb_max(tree));
            
    } else {
        printf("\nÁrbol vacío\n");
    }

    


    char *menu = "\n"
                "--------------------------------------------------------------\n"
				"| 1 ........ Mostrar árbol por pantalla                      |\n"
				"| 2 ........ Agregar un elemento                             |\n"
				"| 3 ........ Eliminar un elemento                            |\n"
				"| 4 ........ Chequear existencia de elemento                 |\n"
				"| 5 ........ Mostrar longitud del árbol                      |\n"
				"| 6 ........ Mostrar raiz, máximo y mínimo del árbol         |\n"
				"| 7 ........ Salir                                           |\n"
                "--------------------------------------------------------------\n";

    int respuesta;
    abb_elem element;
    printf("Only numbers!\n");
    while (respuesta != 7) {
        printf("\n%s\n", menu);        
        printf("Ingrese una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
        case 1:
            abb_dump(tree);
            break;
        case 2:
            printf("Ingrese un elemento: ");
            scanf("%d", &element);
            abb_add(tree, element);
            break;
        case 3:
            printf("Ingrese un elemento: ");
            scanf("%d", &element);
            abb_remove(tree, element);
            break;
        case 4:
            printf("Ingrese un elemento: ");
            scanf("%d", &element);
            printf("El elemento %s existe en el arbol\n", abb_exists(tree, element) ? "si" : "no");
            break;
        case 5:
            printf("El arbol tiene longitud %d\n", abb_length(tree));
            break;
        case 6:
            printf("- Raiz -> %d\n- Minimo -> %d\n- Maximo -> %d\n",
            abb_root(tree), abb_min(tree), abb_max(tree));
            break;
        case 7:
            tree = abb_destroy(tree);
            tree = NULL;
            break;
        default:
            printf("Opcion incorrecta, ingrese 7 para salir");
            break;
        }
        
    }
    return (EXIT_SUCCESS);
}
