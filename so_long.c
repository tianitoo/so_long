#include "so_long.h"


void check_horzontal_wall(char *wall)
{
        printf("here \n");
    while (*wall)
    {
        if (*wall != '1')
        {
            printf("problem in horiwontal line\n");
            exit(0);
        }
        wall++;
    }
}

void check_vertical_wall(char *wall)
{
    if (wall[0] != '1' || wall[ft_strlen(wall) - 1] != '1')
    {
        printf("problem in vertical line\n");
        exit(0);
    }
    
}

char **add_line_map(char **map, char *line, int y)
{
    char **tmp_map;
    int i;

    i = 0;
    tmp_map = (char **) malloc (sizeof(char*) * y);
    // check_horzontal_wall(map[i]);
    while (i < y - 1)
    {
        // check_vertical_wall(map[i]);
        tmp_map [i] = map[i];
        i++;
    }
    // check_horzontal_wall(map[i]);
    tmp_map[i] = line;
    free(map);
    return (tmp_map);
}