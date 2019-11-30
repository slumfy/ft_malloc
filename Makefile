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
	realloc.c

CC = cc 
CFLAG = -Wall -Werror -Wextra -g -I./ -fPIC

FLAG= -shared


INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
			$(CC) $(OBJ) -o$(LIB) $(FLAG)
			rm -f $(NAME)
			ln -s $(LIB) $(NAME)

%.o: %.c ft_malloc.h
		$(CC) $(CFLAG) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f $(LIB)
re:	fclean all
