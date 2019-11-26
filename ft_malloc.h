/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:32:40 by rvalenti          #+#    #+#             */
/*   Updated: 2019/11/26 23:05:29 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define TINY 512
# define SMALL 1024
# define LARGE 4096

# include <stdlib.h>
# include <sys/mman.h>

typedef enum	e_type
{
	E_TINY,
	E_SMALL,
	E_LARGE
}				t_type;

typedef	struct	s_zone
{
	int				status;
	size_t			size;
	struct s_zone	*next;
}				t_zone;

typedef struct	s_env
{
	struct s_zone	tiny;
	struct s_zone	small;
	struct s_zone	large;
}				t_env;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
#endif
