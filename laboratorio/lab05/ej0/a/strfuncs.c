#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


size_t string_length(const char *str)
{
    size_t size = 0;
    bool done = false;
    if (str != NULL)
    {
        while (!done)
        {
            if (str[size] == '\0')
            {
                done = !done;
            }
            else
            {
                size++;
            }
        }
    }
    return size;
}

char *string_filter(const char *str, char c)
{
    size_t length = string_length(str);
    char *res = malloc(sizeof(char) * length);
    unsigned int j = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] != c)
        {
            res[j] = str[i];
            j++;
        }
    }
    return res;
}