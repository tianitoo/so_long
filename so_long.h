/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:00:49 by hnait             #+#    #+#             */
/*   Updated: 2023/03/20 12:04:10 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_vars {
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*dst;
	char	*background;
	char	*wall;
	char	*exit;
	char	*goku;
	char	*dragon_ball;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		i;
	int		j;
	int		number_of_lines_map;
	int		number_of_moves;
	int		number_of_collectables;
	int		number_of_exits;
	int		exit_i;
	int		exit_j;
	size_t	x;
	int		y;
}				t_vars;

char	**add_line_map(char **map, char *line, int y);
void	prompt_error(int nb, char *str);
void	put_img(t_vars *vars, char type);
void	put_player(t_vars *vars, int i, int j);
void	check_vertical_wall(char *wall);
void	check_horzontal_wall(char *wall);
void	reach_collectible_exit(char **path, int i, int j);
void	check_collectables(char **path, int lines);
char	**clone_map(char **map, int y);
int		in_player_reach(int i, int j, char **path, int *changed);
void	check_errors(t_vars *vars);
int		p_reach(char **path, int i, int j, int previously_changed);
void	check_collectables(char **path, int lines);
void	put_collectable(t_vars *vars, int i, int j);
void	put_exit(t_vars *vars, int i, int j);
void	init_imgs(t_vars *vars);
void	check_path(char **path, int y);
void	reach_collectible_exit(char **path, int i, int j);
void	init_window(t_vars vars);
int		close_window(int keycode, t_vars *vars);
void	init_vars(t_vars *vars);

#endif
