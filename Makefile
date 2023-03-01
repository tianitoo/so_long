# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnait <hnait@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 16:24:47 by hnait             #+#    #+#              #
#    Updated: 2023/02/27 03:32:33 by hnait            ###   ########.fr        #
#                                                                              #
# *************************libftprintf*************************************************** #

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
		gnl/get_next_line_utils.c


OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	$(MK) -C ./libft

$(PRINTF):
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