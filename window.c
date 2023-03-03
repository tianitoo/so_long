#include "so_long.h"

void color(char *p)
{
    	*(unsigned int*)p = 0x00FF0000;
}

int	my_mlx_pixel_put(t_vars *vars)
{
	vars->dst = vars->addr + (vars->i * vars->line_length + vars->j * (vars->bits_per_pixel / 8));
    color(vars->dst);
    return (0);
}

int	close_window(int keycode, t_vars *vars)
{
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
    ft_printf("%d\n", keycode);
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
    }
	*(unsigned int*)vars->dst = 0x0000000;
    if (keycode == 122)
        vars->i -= 1;
    if (keycode == 100)
        vars->j += 1;
    if (keycode == 115)
        vars->i += 1;
    if (keycode == 113)
        vars->j -= 1;
    return (0);
}

void init_window(char **map, int y)
{
    t_vars vars;
    int i;
    int j;
    int x;

    x = ft_strlen(map[0]) - 1;
    ft_printf("x: %d, y :%d", x, y);
    vars.i = 0;
    vars.j = 0;
    vars.relative_path = "./dragon_ball.xpm";
	vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, x * 64, y * 64, "Hello world!");
    vars.img = mlx_new_image(vars.mlx, 800, 600);
    vars.dragon_ball = mlx_xpm_file_to_image(vars.mlx, vars.relative_path, &vars.img_width, &vars.img_height);
    vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
    i = 0;
    while (i < y)
    {
        j = 0;
        while (j < x)
        {
            if (map[i][j] == '1')
            {
                mlx_put_image_to_window(vars.mlx, vars.win, vars.dragon_ball, j * 64, i * 64);
            }
            j++;
        }
        i++;
    }
    
    // mlx_key_hook(vars.win, close_window, &vars);
    // mlx_loop_hook(vars.mlx, my_mlx_pixel_put, &vars);
	mlx_loop(vars.mlx);
}