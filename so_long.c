/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:54:39 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 16:16:18 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	check_horzontal_wall(char *wall)
{
	while (*wall)
	{
		if (*wall != '1' && *wall != '\n')
		{
			prompt_error(1, "problem in horizontal wall");
		}
		wall++;
	}
}

void	check_vertical_wall(char *wall)
{
	if (wall[0] != '1' || wall[ft_strlen(wall) - 1] != '1')
	{
		prompt_error(1, "problem in vertical line");
	}
}

void	check_line(char *line)
{
	while (*line)
	{
		if (*line != '1' && *line != '0'
			&& *line != 'P' && *line != 'C'
			&& *line != 'E' && *line != '\n')
		{
			prompt_error(1, "problem in horizontal line");
		}
		line++;
	}
}

char	**add_line_map(char **map, char *line, int y)
{
	char	**tmp_map;
	int		i;

	i = 0;
	tmp_map = (char **) malloc (sizeof(char *) * y);
	while (i < y - 1)
	{
		check_vertical_wall(map[i]);
		check_line(map[i]);
		tmp_map [i] = map[i];
		i++;
	}
	tmp_map[i] = line;
	free(map);
	return (tmp_map);
}
