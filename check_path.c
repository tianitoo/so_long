/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:00:41 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 16:16:52 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		prompt_error(1, "can't reach collectable.");
	if (path[i][j] == 'E')
	{
		if (path[i - 1][j] != 'P' && path[i + 1][j] != 'P'
			&& path[i][j - 1] != 'P' && path[i][j + 1] != 'P')
			prompt_error(1, "can't reach exit");
	}
}

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
