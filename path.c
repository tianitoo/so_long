/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:52:06 by hnait             #+#    #+#             */
/*   Updated: 2023/03/16 09:00:35 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char **path, int y)
{
	int		i;
	size_t	j;
	int		changed;
	int		player_exist;

	changed = 0;
	player_exist = 0;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < ft_strlen(path[i]) - 1)
		{
			if (path[i][j] == 'P')
			{
				changed = p_reach(path, i, j, changed);
				player_exist = 1;
			}
			j++;
		}
		i++;
	}
	if (player_exist == 0)
	{
		ft_printf("player does not exist.\n");
		exit(0);
	}
	if (changed == 1)
		check_path(path, y);
}

int	p_reach(char **path, int i, int j, int previously_changed)
{
	int	changed;

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

void	check_collectables(char **path, int lines)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < ft_strlen(path[i]) - 1)
		{
			reach_collectible_exit(path, i, j);
			j++;
		}
		i++;
	}
}

void	reach_collectible_exit(char **path, int i, int j)
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
