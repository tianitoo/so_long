/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:04:30 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 16:16:38 by hnait            ###   ########.fr       */
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

void	game_done(int error, t_vars *vars, char *str)
{
	mlx_destroy_window(vars->mlx, vars->win);
	prompt_error(error, str);
}

void	print_moves(int i, int j, t_vars *vars)
{
	if (i != vars->i || j != vars->j)
	{
		vars->number_of_moves += 1;
		ft_printf("%d\n", vars->number_of_moves);
	}
}

int	close_window(int keycode, t_vars *vars)
{
	int	i;
	int	j;

	i = vars->i;
	j = vars->j;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
	{
		put_img(vars, '0');
		move_player(vars, keycode);
		if (vars->map[vars->i][vars->j] == 'C')
		{
			put_img(vars, '0');
			vars->number_of_collectables--;
		}
		put_img(vars, 'P');
		print_moves(i, j, vars);
		vars->map[vars->i][vars->j] = 'P';
		if (vars->number_of_collectables == 0)
			put_img(vars, 'E');
		if (vars->i == vars->exit_i && vars->j == vars->exit_j)
			game_done(0, vars, "YOU HAVE WON");
	}
	else if (keycode == 53)
		game_done(0, vars, "player hit exit");
	return (0);
}

void	check_errors(t_vars *vars)
{
	if (vars->i < 0 || vars->j < 0)
		prompt_error(1, "there is no player.");
	if (vars->number_of_collectables == 0)
		prompt_error(1, "there is no collectables");
	if (vars->number_of_exits != 1)
	{
		if (vars->number_of_exits == 0)
			prompt_error(1, "there is no exit");
		else
			prompt_error(1, "too many exits");
	}
}
