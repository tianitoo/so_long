/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:43:52 by hnait             #+#    #+#             */
/*   Updated: 2023/03/16 08:48:49 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**clone_map(char **map, int y)
{
	char	**clone;
	int		i;

	i = 0;
	clone = (char **) malloc (sizeof(char *) * y);
	while (i < y)
	{
		clone[i] = ft_strdup(map[i]);
		i++;
	}
	return (clone);
}

// void f()
// {
// 	system("leaks so_long");
// }

void	prompt_error(int nb, char *str)
{
	ft_printf("ERROR\n%s", str);
	exit(nb);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*gnline;
	char	**map;
	char	**path;
	size_t	x;
	int		y;
	int		the_end;

	the_end = 0;
	if (argc != 2)
	{
		prompt_error(0, "you need to provide a map file\n");
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber\0", 5) != 0)
	{
		prompt_error(0, "you should provide a '.ber' file\n");
	}
	x = 0;
	y = 0;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		prompt_error(0, "map not found");
	}
	while (1)
	{
		gnline = get_next_line(fd);
		if (x != 0 && the_end == 0 && gnline)
		{
			if (gnline[x] == '\0')
			{
				the_end = 1;
			}
		}
		else if (!gnline && the_end != 1)
		{
			prompt_error(0, "map is not rectangle\n");
		}
		line = ft_strtrim(gnline, "\n");
		free(gnline);
		if (!line)
			break ;
		if (x == 0)
		{
			x = ft_strlen(line);
			if (x == 0)
			{
				prompt_error(0, "map is empty");
			}
			check_horzontal_wall(line);
		}
		if (ft_strlen(line) != x)
		{
			prompt_error(0, "problem in line length\n");
		}
		y++;
		map = add_line_map(map, line, y);
	}
	check_horzontal_wall(map[y - 1]);
	path = clone_map(map, y);
	check_path(path, y);
	check_collectables(path, y);
	init_window(map, y);
}
