/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:26:53 by gachibass22       #+#    #+#             */
/*   Updated: 2019/03/05 23:19:02 by gachibass22      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAP_SIZE 21
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef	struct		s_figure
{
	char			alpha;
	char			**figure;
	struct s_figure	*next;
	int				width;
	int				length;
	int				coords[2];
	int				count;
}					t_figure;

void				start_cut(int fd);
int					ft_read_map(int fd);
void				solve_fill(t_figure *lst);
int					fill_it(t_figure *lst, int size);
t_figure			*save_lst(t_figure *lst);
void				free_map(char **map, int size);
void				delete_overlay(t_figure *lst, int size, char **map);
int					check_overlay(int size, char **map);
size_t				optimal_size(t_figure *figures_lst);
char				**create_map(int size);
int					get_width(char tetrimino[22], t_figure *lst);
int					get_length(char tetrimino[22], t_figure *lst);
void				cut_figure(char tetrimino[22], t_figure *lst);
void				change_sharps(t_figure *lst, char **figure);
int					ft_sanya__ne_sdelal(t_figure *lst, int size);
char				**ft_mapcpy(char **map);
void				print_result(char **map);
int					ft_del(char ***map);
int					gogo_place(int x, int y, t_figure *lst);
void				ft_maping(int size);
int					bn_counter(char *buff);
void				free_list(t_figure *figures_lst);

#endif
