

NAME = so_long
CC = cc -Wall -Wextra -Werror
FLAGS = 
AR = ar -r
RM = rm -f
HEAD = so_long.h
MK = make
LIBFT = ./libft/libft.a
HEADLIBFT = ./libft/libft.h
PRINTF = ./ft_printf/ft_printf.a
HEADPRINTF = ./ft_printf/ft_printf.h


SRC = main.c\
		so_long.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		path.c\
		window.c


OBJ = $(SRC:.c=.o)

all: libft ft_printf $(NAME)

libft:
	$(MK) -C ./libft

ft_printf:
	$(MK) -C ./ft_printf

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c $(HEAD)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
clean:
		$(RM) $(OBJ)
		$(MK) clean -C libft
		$(MK) clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(PRINTF)
	

re: fclean all

.PHONY: all bonus clean fclean re libft ft_printf