/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:52:06 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 12:01:51 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_right_down(int y, int *player_exist, int *changed, char **path)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < y - 1)
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

	y--;
	while (y > 1)
	{
		j = ft_strlen(path[y]) - 2;
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
