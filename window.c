/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:04:30 by hnait             #+#    #+#             */
/*   Updated: 2023/03/16 22:54:15 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_vars *vars, int keycode)
{
	if (keycode == 13 && vars->map[vars->i - 1][vars->j] != '1'
			&& vars->map[vars->i - 1][vars->j] != 'E')
		vars->i -= 1;
	else if (keycode == 2 && vars->map[vars->i][vars->j + 1] != '1'
			&& vars->map[vars->i][vars->j + 1] != 'E')
		vars->j += 1;
	else if (keycode == 1 && vars->map[vars->i + 1][vars->j] != '1'
			&& vars->map[vars->i + 1][vars->j] != 'E')
		vars->i += 1;
	else if (keycode == 0 && vars->map[vars->i][vars->j - 1] != '1'
			&& vars->map[vars->i][vars->j - 1] != 'E')
		vars->j -= 1;
}

int	close_window(int keycode, t_vars *vars)
{
	int	i;
	int	j;

	i = vars->i;
	j = vars->j;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, vars->j * 64, vars->i * 64);
		move_player(vars, keycode);
		if (vars->map[vars->i][vars->j] == 'C')
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->background, vars->j * 64, vars->i * 64);
			vars->number_of_collectables--;
		}
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->goku, vars->j * 64, vars->i * 64);
		if (i != vars->i || j != vars->j)
		{
			vars->number_of_moves += 1;
			ft_printf("%d\n", vars->number_of_moves);
		}
		vars->map[vars->i][vars->j] = '0';
		vars->map[vars->i][vars->j] = 'P';
		if (vars->number_of_collectables == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->background, vars->exit_j * 64, vars->exit_i * 64);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->exit, vars->exit_j * 64, vars->exit_i * 64);
			vars->map[vars->exit_i][vars->exit_j] = 'e';
		}
		if (vars->i == vars->exit_i && vars->j == vars->exit_j)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			prompt_error(1, "YOU HAVE WON.\n");
		}
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		prompt_error(0, "player hit exit");
	}
	return (0);
}

void	init_imgs(t_vars *vars)
{
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./exit.xpm",
			&vars->img_width, &vars->img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./wall.xpm",
			&vars->img_width, &vars->img_height);
	vars->goku = mlx_xpm_file_to_image(vars->mlx, "./goku_right.xpm",
			&vars->img_width, &vars->img_height);
	vars->background = mlx_xpm_file_to_image(vars->mlx, "./background.xpm",
			&vars->img_width, &vars->img_height);
	vars->dragon_ball = mlx_xpm_file_to_image(vars->mlx, "./dragon_ball.xpm",
			&vars->img_width, &vars->img_height);
	if (!vars->exit || !vars->wall || !vars->goku
		|| !vars->background || !vars->dragon_ball)
		prompt_error(0, "image does not exist");
}

void	put_player(t_vars *vars, int i, int j)
{
	if (vars->i != -1 || vars->j != -1)
		prompt_error(0, "too many players");
	vars->i = i;
	vars->j = j;
}

void	put_collectable(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->dragon_ball, j * 64, i * 64);
	vars->number_of_collectables++;
}

void	put_exit(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, j * 64, i * 64);
	vars->number_of_exits++;
	vars->exit_i = i;
	vars->exit_j = j;
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
			vars->y * 64, "Hello world!");
	vars->img = mlx_new_image(vars->mlx, 800, 600);
	init_imgs(vars);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}

void	check_errors(t_vars *vars)
{
	if (vars->i < 0 || vars->j < 0)
	{
		prompt_error(0, "there is no player.\n");
	}
	if (vars->number_of_collectables == 0)
	{
		prompt_error(0, "there is no collectables\n");
	}
	if (vars->number_of_exits != 1)
	{
		if (vars->number_of_exits == 0)
			prompt_error(0, "there is no exit\n");
		else
			prompt_error(0, "too many exits\n");
	}
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
			mlx_put_image_to_window(vars.mlx, vars.win,
				vars.background, j * 64, i * 64);
			if (vars.map[i][j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.wall, j * 64, i * 64);
			if (vars.map[i][j] == 'C')
				put_collectable(&vars, i, j);
			if (vars.map[i][j] == 'P')
				put_player(&vars, i, j);
			if (vars.map[i][j] == 'E')
				put_exit(&vars, i, j);
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
