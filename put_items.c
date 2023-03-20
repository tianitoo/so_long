/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:26:11 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 11:38:09 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_vars *vars, char type)
{
	void	*p;

	if (type == '0')
		p = vars->background;
	if (type == 'P')
		p = vars->goku;
	if (type == '1')
		p = vars->wall;
	if (type == 'C')
	{
		p = vars->dragon_ball;
		vars->number_of_collectables++;
	}
	if (type == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->background, vars->exit_j * 64, vars->exit_i * 64);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit, vars->exit_j * 64, vars->exit_i * 64);
		vars->map[vars->exit_i][vars->exit_j] = 'e';
		return ;
	}
	mlx_put_image_to_window(vars->mlx, vars->win,
		p, vars->j * 64, vars->i * 64);
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
