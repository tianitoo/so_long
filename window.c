#include "so_long.h"

int	my_mlx_pixel_put(t_vars *vars)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->goku, vars->j * 64, vars->i * 64);
    return (0);
}

int	close_window(int keycode, t_vars *vars)
{
    ft_printf("%d\n", keycode);
    vars->map[vars->i][vars->j] = '0';
    mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->j * 64, vars->i * 64);
    if (keycode == 122 && vars->map[vars->i - 1][vars->j] != '1' && vars->map[vars->i - 1][vars->j] != 'E')
        vars->i -= 1;
    else if (keycode == 100 && vars->map[vars->i][vars->j + 1] != '1' && vars->map[vars->i][vars->j + 1] != 'E')
        vars->j += 1;
    else if (keycode == 115 && vars->map[vars->i + 1][vars->j] != '1' && vars->map[vars->i + 1][vars->j] != 'E')
        vars->i += 1;
    else if (keycode == 113 && vars->map[vars->i][vars->j - 1] != '1' && vars->map[vars->i][vars->j - 1] != 'E')
        vars->j -= 1;
    else if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
    }
    else
        return (0);
    vars->map[vars->i][vars->j] = 'P';
    return (0);
}

void init_window(char **map, int y)
{
    t_vars vars;
    char    *background;
    char    *wall;
    char    *dragon_ball;
    char    *goku;
    int x;
    int i;
    int j;
    
    x = ft_strlen(map[0]) - 1;
    vars.map = map;
    vars.number_of_lines_map = y;
    vars.i = 0;
    vars.j = 0;
    background = "./background.xpm";
    wall = "./wall.xpm";
    goku = "./goku_right.xpm";
    dragon_ball = "./dragon_ball.xpm";
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, x * 64, y * 64, "Hello world!");
    vars.img = mlx_new_image(vars.mlx, 800, 600);
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
            }
            if (vars.map[i][j] == 'P')
            {
                vars.i = i;
                vars.j = j;
            }
            j++;
        }
        i++;
    }
    mlx_key_hook(vars.win, close_window, &vars);
    mlx_loop_hook(vars.mlx, my_mlx_pixel_put, &vars);
	mlx_loop(vars.mlx);
}