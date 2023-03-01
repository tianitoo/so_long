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
        ft_printf("%s\n", line);
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
