#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"


char **add_line_map(char **map, char *line, int y);
void check_vertical_wall(char *wall);
void check_horzontal_wall(char *wall);
char **clone_map(char **map, int y);
int P_reach(char **path, int i, int j, int previously_changed);
void check_path(char **path, int y);

#endif
