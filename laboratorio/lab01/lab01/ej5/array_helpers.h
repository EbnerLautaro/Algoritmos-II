#ifndef array_helpers

    unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

    void array_dump(int a[], unsigned int length);

    mybool array_is_sorted(int array[], unsigned int length);


#endif
// la compilacion falla porque estoy incluyendo dos veces la misma definicion.