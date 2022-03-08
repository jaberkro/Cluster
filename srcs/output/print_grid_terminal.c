/* Created by jaberkro on march 5th 22. */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "cluster.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define GRY   "\x1B[90m"
#define RESET "\x1B[0m"

void    print_grid_terminal(int opta, int optb)
{
	char *grid = generated_map(5);

    get_indices(get_opposite_direction(g_field.gravity));
    char	*items_double[5] = { WHT"{}"RESET, RED"##"RESET, YEL"@@"RESET, GRN"$$"RESET, BLU"&&"RESET };
    char	*items_A[5] = { WHT"A"RESET, RED"A"RESET, YEL"A"RESET, GRN"A"RESET, BLU"A"RESET };
    char	*items_B[5] = { WHT"B"RESET, RED"B"RESET, YEL"B"RESET, GRN"B"RESET, BLU"B"RESET };
    char    c;
    int     i = 0;
	int		iter = 0;
    
    while (1)
    {
		c = grid[iter++];
        if (c == '.' || c == '\0')
            break;
        else if (c == '}')
            ;
        else if (c == '{')
        {
            printf("%s", items_double[tile_arr[tile_order[i]]->tile_colour]);
            i++;
        }
        else if (c == '|' || c == 'v')
            printf(GRY "%c", c);
        else if (c == 'A') {
            printf("%s", items_A[opta]);
        }
        else if (c == 'B') {
            printf("%s", items_B[optb]);
        }
        else
            printf(WHT "%c", c);
    }
    printf("\n");
}
