/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:27:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/13 19:08:15 by mbeahan          ###   ########.fr       */
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

typedef struct	s_figure
{
	char			alpha;
	char 			**figure;
	struct s_figure	*next;
	int				width;
	int				length;
}				t_figure;

void	start_cut(int fd);
int			ft_read_map(int fd);
int			get_width(char tetrimino[22], int *x);
int		get_length(char tetrimino[22], int *y);
void	cut_figure(char tetrimino[22], int *m[2], t_figure *lst);
void	change_sharps(t_figure *lst, char **figure);
void   solve_fill(t_figure *lst);
int fill_map(t_figure *lst, int size,char **map);
void delete_overlay(t_figure *lst, int size, char **map);
int check_overlay(int size, char **map);
size_t  optimal_size(t_figure *figures_lst);
void    create_map(t_figure *lst, int size, char **map);
void print_figures(t_figure *lst);


#endif