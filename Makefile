# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 12:10:29 by rvalenti          #+#    #+#              #
#    Updated: 2019/11/29 03:48:20 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = ft_malloc
SRC =	malloc.c\
	show_alloc_mem.c\
	test.c

LIBFT = ./libft/
CC = gcc -Wall -Werror -Wextra -fsanitize=address -g

INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME): $(OBJ)
			make -C $(LIBFT)
			$(CC) $(OBJ) -o$(NAME) -I$(LIBFT) -I$(INCLUDES) -L $(LIBFT) -lft

%.o: %.c 
		$(CC) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
re:	fclean all
