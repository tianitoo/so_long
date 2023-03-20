/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:43:52 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 11:57:03 by hnait            ###   ########.fr       */
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

char	*get_line(int fd, int *the_end, int x)
{
	char	*line;
	char	*gnline;

	gnline = get_next_line(fd);
	if (x != 0 && *the_end == 0 && gnline)
	{
		if (gnline[x] == '\0')
			*the_end = 1;
	}
	else if (!gnline && *the_end != 1)
		prompt_error(0, "map is not rectangle\n");
	line = ft_strtrim(gnline, "\n");
	free(gnline);
	return (line);
}

void	check_map_lines(t_vars *vars, char *line)
{
	if (vars->x == 0)
	{
		vars->x = ft_strlen(line);
		if (vars->x > 256)
			prompt_error(0, "too many line in map");
		if (vars->x == 0)
			prompt_error(0, "map is empty");
		check_horzontal_wall(line);
	}
}

void	check_map(t_vars *vars, int fd)
{
	int		the_end;
	char	*line;

	the_end = 0;
	while (1)
	{
		line = get_line(fd, &the_end, vars->x);
		if (!line)
			break ;
		check_map_lines(vars, line);
		if (ft_strlen(line) != vars->x)
			prompt_error(0, "problem in line length");
		vars->y++;
		if (vars->y > 256)
			prompt_error(0, "too many lines in line");
		vars->map = add_line_map(vars->map, line, vars->y);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**path;
	t_vars	vars;

	vars.x = 0;
	vars.y = 0;
	vars.map = NULL;
	if (argc != 2)
		prompt_error(0, "you need to provide a map file\n");
	if (!ft_strrchr(argv[1], '.'))
		prompt_error(0, "you should provide a '.ber' file\n");
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber\0", 5) != 0)
		prompt_error(0, "you should provide a '.ber' file\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		prompt_error(0, "map not found");
	check_map(&vars, fd);
	check_horzontal_wall(vars.map[vars.y - 1]);
	path = clone_map(vars.map, vars.y);
	check_path(path, vars.y);
	check_collectables(path, vars.y);
	init_window(vars);
}
