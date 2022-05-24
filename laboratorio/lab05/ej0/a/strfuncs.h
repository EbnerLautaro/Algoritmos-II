#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__


// Calcula y retorna el largo de una cadena
size_t string_length(const char *str);

// Devuelve una cadena sin los caracteres iguales a c
char *string_filter(const char *str, char c);

#endif