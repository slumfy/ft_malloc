/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:32:40 by rvalenti          #+#    #+#             */
/*   Updated: 2019/12/02 10:38:09 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define TINY 4096
# define SMALL 1024 * 32

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <string.h>

# include <stdio.h>

typedef enum	e_type
{
	E_TINY,
	E_SMALL,
	E_LARGE,
	E_ERROR
}				t_type;

typedef	struct	s_zone
{
	int				status;
	size_t			size;
	struct s_zone	*next;
}				t_zone;

typedef	struct	s_page
{
	size_t			size;
	struct s_page	*previous;
	struct s_page	*next;
	struct s_zone	*zone;
}				t_page;

typedef struct	s_env
{
	struct s_page	*tiny;
	struct s_page	*small;
	struct s_page	*large;
}				t_env;

struct s_env			g_env;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

t_type			get_type(size_t size);
t_zone			*create_zone(t_zone *zone, size_t size);
t_page			*check_env(t_type type, size_t size);
void			create_page(t_type type, size_t size);
void			set_page_to_env(void *map, t_type type);
void			*ret_zone(void *zone, t_type type);
size_t			get_size(t_type type, size_t size);
void			*check_mem(t_type type, size_t size);
int				check_is_zone(t_zone *zone);

void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_bzero(void *s, size_t n);
void			print_addr(uint64_t nb);
#endif
