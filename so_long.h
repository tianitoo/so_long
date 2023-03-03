#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*dragon_ball;
	char	*addr;
	char	*dst;
	char	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		i;
	int		j;
}				t_vars;

char **add_line_map(char **map, char *line, int y);
void check_vertical_wall(char *wall);
void check_horzontal_wall(char *wall);
char **clone_map(char **map, int y);
int P_reach(char **path, int i, int j, int previously_changed);
void check_collectables(char **path, int lines);
void check_path(char **path, int y);
void reach_collectible_exit(char **path, int i, int j);
void init_window(char **map, int y);

int	close_window(int keycode, t_vars *vars);


#endif
