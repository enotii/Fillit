/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristinazueva <kristinazueva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:27:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/04 21:00:25 by kristinazue      ###   ########.fr       */
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

typedef struct		s_figure
{
	char			**figure;
	struct s_figure	*next;
}					t_figure;

int ft_read_map(int fd);
t_figure ft_fill_read(int fd, t_figure *result);
void ft_fill_parsing(t_figure **result, char buff[21], char ch);
void ft_split(char *buff);
int ft_empty(char *str);
int fill_last_fig(char **split);
int fill_begin_fig(char **split);
char *fig_memmalloc(char *split, int begin_fig, int last_fig);
void fill_list(t_figure **list, char ***split);


#endif