# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 12:10:29 by rvalenti          #+#    #+#              #
#    Updated: 2019/11/19 14:39:27 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malloc
SRC =

LIBFT = ./libft/
CC = gcc -Wall -Werror -Wextra -fsanitize=address -g

INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(CHECK) $(NAME)

CHECK:
ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

$(NAME): $(OBJ)
			make -C $(LIBFT)
			echo $(HOSTTYPE)

%.o: %.c 
		$(CC) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
re:	fclean all
