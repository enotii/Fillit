/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:27:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/11 17:51:52 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define MAP_SIZE 21
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# define PINK(x) "\033[35;1m" x "\033[0m"
# define GREEN(x) "\033[32;1m" x "\033[0m"

typedef struct	s_figure
{
	char 			**figure;
	struct s_figure	*next;
	int				width;
	int				length;
}				t_figure;

t_figure	*start_cut(int fd);
int			ft_read_map(int fd);
void print_figures(t_figure *figures_lst);

#endif
