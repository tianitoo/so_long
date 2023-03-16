/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:52:06 by hnait             #+#    #+#             */
/*   Updated: 2023/03/16 23:13:34 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	in_player_reach(int i, int j, char **path, int *changed)
{
	int	player_exist;

	player_exist = 0;
	if (path[i][j] == 'P')
	{
		*changed = p_reach(path, i, j, *changed);
		return (1);
	}
	return (0);
}

void	path_right_down(int y, int *player_exist, int *changed, char **path)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < ft_strlen(path[i]) - 1)
		{
			if (in_player_reach(i, j, path, changed))
				*player_exist = 1;
			j++;
		}
		i++;
	}
}

void	path_left_up(int y, int *player_exist, int *changed, char **path)
{
	int	j;
	while (y > 0)
	{
		j = ft_strlen(path[y]) - 1;
		while (j > 1)
		{
			if (in_player_reach(y, j, path, changed))
				*player_exist = 1;
			j--;
		}
		y--;
	}
}

void	check_path(char **path, int y)
{
	int		changed;
	int		player_exist;

	changed = 0;
	player_exist = 0;
	path_right_down(y, &player_exist, &changed, path);
	path_left_up(y, &player_exist, &changed, path);
	if (player_exist == 0)
		prompt_error(0, "player does not exist.\n");
	if (changed == 1)
		check_path(path, y);
}

void	player_reach_near(char **path, int i, int j, int *changed)
{
	if (path[i][j] == '0' || path[i][j] == 'C')
	{
		path[i][j] = 'P';
		*changed = 1;
	}
}

int	p_reach(char **path, int i, int j, int previously_changed)
{
	int	changed;

	changed = previously_changed;
	player_reach_near(path, i + 1, j, &changed);
	player_reach_near(path, i - 1, j, &changed);
	player_reach_near(path, i, j + 1, &changed);
	player_reach_near(path, i, j - 1, &changed);
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
