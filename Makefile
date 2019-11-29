# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 12:10:29 by rvalenti          #+#    #+#              #
#    Updated: 2019/11/29 10:49:24 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so
SRC =	malloc.c\
	malloc_utils.c\
	show_alloc_mem.c\
	free.c\
	page.c\
	realloc.c\
	test.c

LIBFT = ./libft/
LIBFTA = ./libft/libft.a

CC = gcc -Wall -Werror -Wextra

INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME): $(OBJ)
			make -C $(LIBFT)
			$(CC) -shared $(OBJ) -o$(LIB) $(LIBFTA)
			ln -s $(LIB) $(NAME)

%.o: %.c 
		$(CC) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make clean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME)
		rm -f $(LIB)
		make fclean -C $(LIBFT)
re:	fclean all
