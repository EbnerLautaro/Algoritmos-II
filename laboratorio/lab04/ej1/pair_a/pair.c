#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./pair.h"

pair_t pair_new(int x, int y) {
    pair_t a;
    a.fst = x;
    a.snd = y;
    return a;
}

int pair_first(pair_t p) {
    return p.fst;
}

int pair_second(pair_t p) {
    return p.snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t temp;
    temp.fst = p.snd;
    temp.snd = p.fst;
    return temp; 
}

pair_t pair_destroy(pair_t p) {
    return p; 
    // No se puede liberear memoria que no aloqué 
    // https://stackoverflow.com/a/71172623

}