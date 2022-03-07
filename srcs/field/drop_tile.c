//
// Created by Peer De bakker on 3/6/22.
//

#include "cluster.h"
#include <assert.h>

void    drop_downwards(t_tile *tile) {
    const int   grav = g_field.gravity;
    t_tile      *down = tile->neighbours[grav];

    print_grid_terminal();
    usleep(200000);
    if (down && down->tile_colour == 0) {
        down->tile_colour = tile->tile_colour;
        tile->tile_colour = 0;
        drop_downwards(down);
    }
}

void    get_drop_tile(int pos, int colour) {
    // assuming 1 is the leftmost drop you can make
    const int upwards = get_opposite_direction(g_field.gravity);
    t_tile  *drop_tile = g_field.corners[upwards];
    int start = 5; // because it's in the middle (check the figure Jorien made)
    int movedirection;
    int delta = 1;

    if (pos < start) {
        movedirection = get_next_direction(g_field.gravity);
        delta = -1;
    }
    else
        movedirection = get_previous_direction(g_field.gravity);
    
    while (pos != start) {
        printf("pos = %d\n", pos);
        printf("drop_tile: %p, %d, %d\n", (void*)drop_tile, drop_tile->idx, drop_tile->tile_colour);
        drop_tile = drop_tile->neighbours[movedirection];
        start += delta;
    }
    printf("FINAL drop_tile: %p, %d, %d\n", (void*)drop_tile, drop_tile->idx, drop_tile->tile_colour);
    if (drop_tile->tile_colour) {
        // has already been filled
        printf("Damn son, the tile you chose already is filled, what a shitty move!\n");
        return ;
    }
    if (!drop_tile->alive) {
        printf("how are you gonna drop your tile right onto a dead one?\n");
        return;
    }
    drop_tile->tile_colour = colour;
    printf("colour = %d\n", colour);
    drop_downwards(drop_tile);
}
