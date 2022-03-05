/* Created by jaberkro on march 5th 22. */

#include <stdio.h>
#include <unistd.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void    print_grid(void)
{
    FILE *grid = fopen("grid5.txt", "r");
    char c;
    
    while (1)
    {
        c = getc(grid);
        if (c == '.')
            break;
        if (c == '{' || c == '}')
            printf(RED "%c", c);
        else
            printf(WHT "%c", c);
    } 
}

// int main(void)
// {
//     print_grid();
//     return (1);
// }
