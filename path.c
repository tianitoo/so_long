#include "so_long.h"

void check_path(char **path, int y)
{
    int i;
    size_t j;
    int changed;

    changed = 0;
    i = 0;
    while (i < y)
    {
        j = 0;
        while (j < ft_strlen(path[i]) - 2)
        {
            if (path[i][j] == 'P')
                changed = P_reach(path, i, j, changed);
            j++;
        }
        i++;
    }
    if (changed == 1)
        check_path(path, y);
}

int P_reach(char **path, int i, int j, int previously_changed)
{
    int changed;

    changed = previously_changed;
    if (path[i + 1][j] == '0' || path[i + 1][j] == 'C')
    {
        path[i + 1][j] = 'P';
        changed = 1;
    }
    if (path[i - 1][j] == '0' || path[i - 1][j] == 'C')
    {
        path[i - 1][j] = 'P';
        changed = 1;
    }
    if (path[i][j + 1] == '0' || path[i][j + 1] == 'C')
    {
        path[i][j + 1] = 'P';
        changed = 1;
    }
    if (path[i][j - 1] == '0' || path[i][j - 1] == 'C')
    {
        path[i][j - 1] = 'P';
        changed = 1;
    }
    return (changed);
}

void check_collectables(char **path, int lines)
{
    int i;
    size_t j;

    i = 0;
    while (i < lines)
    {
        j = 0;
        while (j < ft_strlen(path[i]) - 2)
        {
            reach_collectible_exit(path, i, j);
            j++;
        }
        i++;
    }
}

void reach_collectible_exit(char **path, int i, int j)
{
    if (path[i][j] == 'C')
    {
        ft_printf("can't reach collectable.\n");
        exit(0);
    }
    if (path[i][j] == 'E')
    {
        if (path[i - 1][j] != 'P' && path[i + 1][j] != 'P' 
            && path[i][j - 1] != 'P' && path[i][j + 1] != 'P')
        {
            ft_printf("can't reach exit\n");
            exit(0);
        }
    }
}