

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
		path.c


OBJ = $(SRC:.c=.o)

all: libft ft_printf $(NAME)

libft:
	$(MK) -C ./libft

ft_printf:
	$(MK) -C ./ft_printf

$(NAME): $(OBJ)
	$(CC) $^ $(LIBFT) $(PRINTF) -o $@

%.o : %.c $(HEAD)
		$(CC) -c $< -o $@ $(FLAGS)

clean:
		$(RM) $(OBJ)
		$(MK) clean -C libft
		$(MK) clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(PRINTF)
	

re: fclean all

.PHONY: all bonus clean fclean re