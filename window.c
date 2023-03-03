#include "so_long.h"

int	close_window(int keycode, t_vars *vars)
{
    int i;
    int j;

    i = vars->i;
    j = vars->j;
    if (keycode == 122 || keycode == 100 || keycode == 115 || keycode == 113)
    {
        mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->j * 64, vars->i * 64);
        if (keycode == 122 && vars->map[vars->i - 1][vars->j] != '1' && vars->map[vars->i - 1][vars->j] != 'E')
            vars->i -= 1;
        else if (keycode == 100 && vars->map[vars->i][vars->j + 1] != '1' && vars->map[vars->i][vars->j + 1] != 'E')
            vars->j += 1;
        else if (keycode == 115 && vars->map[vars->i + 1][vars->j] != '1' && vars->map[vars->i + 1][vars->j] != 'E')
            vars->i += 1;
        else if (keycode == 113 && vars->map[vars->i][vars->j - 1] != '1' && vars->map[vars->i][vars->j - 1] != 'E')
            vars->j -= 1;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->goku, vars->j * 64, vars->i * 64);
        if (vars->map[vars->i][vars->j] == 'C')
        {
            vars->number_of_collectables--;
        }
        if (i != vars->i || j != vars->j)
        {
            vars->number_of_moves += 1;
            ft_printf("%d\n", vars->number_of_moves);
        }
        vars->map[vars->i][vars->j] = '0';
        vars->map[vars->i][vars->j] = 'P';
        if (vars->number_of_collectables == 0)
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, vars->exit_j * 64, vars->exit_i * 64);
            vars->map[vars->exit_i][vars->exit_j] = 'e';
        }
        if (vars->i == vars->exit_i && vars->j == vars->exit_j)
        {
            mlx_destroy_window(vars->mlx, vars->win);
            exit(1);
        }
    }
    else if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(1);
    }
    else
    {
        return (0);
    }
    return (0);
}

void init_window(char **map, int y)
{
    t_vars vars;
    char    *background;
    char    *wall;
    char    *dragon_ball;
    char    *goku;
    char    *exits;
    int x;
    int i;
    int j;
    
    x = ft_strlen(map[0]) - 1;
    vars.map = map;
    vars.number_of_lines_map = y;
    vars.number_of_moves = 0;
    vars.number_of_collectables = 0;
    vars.number_of_exits = 0;
    vars.i = 0;
    vars.j = 0;
    exits = "exit.xpm";
    background = "./background.xpm";
    wall = "./wall.xpm";
    goku = "./goku_right.xpm";
    dragon_ball = "./dragon_ball.xpm";
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, x * 64, y * 64, "Hello world!");
    vars.img = mlx_new_image(vars.mlx, 800, 600);
    vars.exit = mlx_xpm_file_to_image(vars.mlx, exits, &vars.img_width, &vars.img_height);
    vars.wall = mlx_xpm_file_to_image(vars.mlx, wall, &vars.img_width, &vars.img_height);
    vars.goku = mlx_xpm_file_to_image(vars.mlx, goku, &vars.img_width, &vars.img_height);
    vars.background = mlx_xpm_file_to_image(vars.mlx, background, &vars.img_width, &vars.img_height);
    vars.dragon_ball = mlx_xpm_file_to_image(vars.mlx, dragon_ball, &vars.img_width, &vars.img_height);
    vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
    x = ft_strlen(vars.map[0]) - 1;
    i = 0;
    while (i < vars.number_of_lines_map)
    {
        j = 0;
        while (j < x)
        {
                mlx_put_image_to_window(vars.mlx, vars.win, vars.background, j * 64, i * 64);
            
            if (vars.map[i][j] == '1')
            {
                mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, j * 64, i * 64);
            }
            if (vars.map[i][j] == 'C')
            {
                mlx_put_image_to_window(vars.mlx, vars.win, vars.dragon_ball, j * 64, i * 64);
                vars.number_of_collectables++;
            }
            if (vars.map[i][j] == 'P')
            {
                vars.i = i;
                vars.j = j;
            }
            if (vars.map[i][j] == 'E')
            {
                mlx_put_image_to_window(vars.mlx, vars.win, vars.wall, j * 64, i * 64);
                vars.number_of_exits++;
                vars.exit_i = i;
                vars.exit_j = j;
            }
            j++;
        }
        i++;
    }
    if (vars.number_of_collectables == 0)
    {
        printf("there is no collectables\n");
        exit(0);
    }
    if (vars.number_of_exits != 1)
    {
        if (vars.number_of_exits == 0)
            printf("there is no exit\n");
        else
            printf("there is many exits\n");
        exit(0);
    }
    
    mlx_put_image_to_window(vars.mlx, vars.win, vars.goku, vars.j * 64, vars.i * 64);
    mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
}