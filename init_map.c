/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:46:25 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 16:17:22 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_vars *vars)
{
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./textures/exit.xpm",
			&vars->img_width, &vars->img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./textures/wall.xpm",
			&vars->img_width, &vars->img_height);
	vars->goku = mlx_xpm_file_to_image(vars->mlx, "./textures/goku_right.xpm",
			&vars->img_width, &vars->img_height);
	vars->background = mlx_xpm_file_to_image(vars->mlx, "./textures/background.xpm",
			&vars->img_width, &vars->img_height);
	vars->dragon_ball = mlx_xpm_file_to_image(vars->mlx, "./textures/dragon_ball.xpm",
			&vars->img_width, &vars->img_height);
	if (!vars->exit || !vars->wall || !vars->goku
		|| !vars->background || !vars->dragon_ball)
		prompt_error(1, "image does not exist");
}

void	create_map(int i, int j, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->background, j * 64, i * 64);
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall, j * 64, i * 64);
	if (vars->map[i][j] == 'C')
		put_collectable(vars, i, j);
	if (vars->map[i][j] == 'P')
		put_player(vars, i, j);
	if (vars->map[i][j] == 'E')
		put_exit(vars, i, j);
}

void	init_window(t_vars vars)
{
	int		x;
	int		i;
	int		j;

	x = ft_strlen(vars.map[0]);
	init_vars(&vars);
	i = 0;
	while (i < vars.number_of_lines_map)
	{
		j = 0;
		while (j < x)
		{
			create_map(i, j, &vars);
			j++;
		}
		i++;
	}
	check_errors(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win,
		vars.goku, vars.j * 64, vars.i * 64);
	mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
}

void	init_vars(t_vars *vars)
{
	vars->number_of_lines_map = vars->y;
	vars->number_of_moves = 0;
	vars->number_of_collectables = 0;
	vars->number_of_exits = 0;
	vars->i = -1;
	vars->j = -1;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->x * 64,
			vars->y * 64, "so long");
	init_imgs(vars);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}

void	prompt_error(int error, char *str)
{
	if (error == 1)
		ft_printf("ERROR\n");
	ft_printf("%s\n", str);
	exit(error);
}
