/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    // para ver si un jugador va primero en relacion a otro comparamos por el campo "rank"
    return x.rank <= y.rank; 
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}


void swap_players(player_t a[], unsigned int pos1, unsigned int pos2) 
{
    player_t temp = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = temp;
}

unsigned int best_player_pos(player_t a[], unsigned int lft, unsigned int rgt) 
{
    unsigned int pos;
    for ( unsigned int i = lft; i < rgt; i++)
    {
        if (i==lft) {
            pos = i;
        }else if (goes_before(a[i], a[pos])){
            pos = i;
        }
    }
    return pos;
}

void sort(player_t a[], unsigned int length) {
    // SELECTION SORT IMPLEMENTATION
    unsigned int best_player;
    for (unsigned int i = 0u; i < length; i++)
    {
        best_player = best_player_pos(a,i,length);
        swap_players(a,i, best_player);
    }
    


}

