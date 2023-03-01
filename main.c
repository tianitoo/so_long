#include "so_long.h"


int main()
{
    int fd;
    char *line;
    char **map;
    size_t x;
    int y;
    int i = 0;

    x = 0;
    fd = open("map.beq", O_RDONLY);
    while (1)
    {

        line = get_next_line(fd);
        if (!line)
            break;
        if (x == 0)
            x = ft_strlen(line);
        if (ft_strlen(line) != x)
        {
            printf("problem in line length\n");
            exit(0);
        }
        y++;
        map = add_line_map(map, line, y);
    }
    while (i < y)
    {
        printf("%s", map[i++]);
    }
}

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