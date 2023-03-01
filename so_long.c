#include "so_long.h"


void check_horzontal_wall(char *wall)
{
    while (*wall)
    {
        if (*wall != '1' && *wall != '\n')
        {
            printf("problem in horiwontal wall\n");
            exit(0);
        }
        wall++;
    }
}

void check_vertical_wall(char *wall)
{
    if (wall[0] != '1' || wall[ft_strlen(wall) - 2] != '1')
    {
        printf("problem in vertical line\n");
        exit(0);
    }
    
}

void check_line(char *line)
{
    while (*line)
    {
        if (*line != '1' && *line != '0' 
            && *line != 'P' && *line != 'C' 
                && *line != 'E' && *line != '\n')
        {
            printf("problem in horiwontal line\n");
            exit(0);
        }
        line++;
    }
}

char **add_line_map(char **map, char *line, int y)
{
    char **tmp_map;
    int i;

    i = 0;
    tmp_map = (char **) malloc (sizeof(char*) * y);
    while (i < y - 1)
    {
        check_vertical_wall(map[i]);
        check_line(map[i]);
        tmp_map [i] = map[i];
        i++;
    }
    tmp_map[i] = line;
    free(map);
    return (tmp_map);
}