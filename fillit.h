/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristinazueva <kristinazueva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:27:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/06 15:38:18 by kristinazue      ###   ########.fr       */
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

int 		ft_read_map(int fd);
t_figure 	*ft_fill_read(int fd, t_figure *result);
void 		ft_fill_parsing(t_figure **result, char buff[21], char ch);
void 		ft_split(char *buff);
int 		ft_empty(char *str);
int 		fill_last_fig(char **split);
int 		fill_begin_fig(char **split);
char 		*fig_memmalloc(char *split, int begin_fig, int last_fig);
void 		fill_list(t_figure **list, char ***split);
char 		**fill_cycle(t_figure *tetriminos);
size_t		find_size(t_figure *tetriminos);
void 		ft_maping(size_t size);
int 		fill_it(t_figure *tetriminos, size_t size);
void 		fill_map(t_figure *tetriminos, int *width, int *height);
int 		go_go_place(int xt, int yt, t_figure *tetriminos);
int 		ft_del(char ***map);
char 		**ft_mapcpy(char **map);
void		print_result(char **map);
void 		find_place(int xt, int yt, t_figure *tetriminos);

#endif