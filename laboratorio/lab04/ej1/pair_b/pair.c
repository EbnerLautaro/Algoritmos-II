#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./pair.h"

pair_t pair_new(int x, int y)
{
    pair_t p = NULL;
    p = malloc(sizeof(struct s_pair_t));
    (*p).fst = x;
    (*p).snd = y;

    // tambien puedo usar -> en vez de *<puntero>.<atributo>
    return p;
}

int pair_first(pair_t p)
{
    return p->fst;
}

int pair_second(pair_t p)
{
    return p->snd;
}

pair_t pair_swapped(pair_t p)
{
    pair_t temp = NULL;
    temp = malloc(sizeof(struct s_pair_t));
    temp->fst = p->snd;
    temp->snd = p->fst;
    return temp;

}

pair_t pair_destroy(pair_t p) {
    free(p);
    return p;
}