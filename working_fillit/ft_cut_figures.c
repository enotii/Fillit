/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:12:41 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/21 16:23:22 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_sharps(t_figure *lst, char **figure)
{
	int			i;
	int			j;
	static int	temp;
	int			width;
	int			length;

	length = 0;
	i = 0;
	j = 0;
	lst->figure = (char **)malloc(sizeof(char *) * lst->length);
	while (length != lst->length)
	{
		width = 0;
		lst->figure[length] = (char *)malloc(sizeof(char) * (lst->width + 1));
		while (width != lst->width)
		{
			if (figure[length][width] == '#')
				figure[length][width] = temp + 65;
			lst->figure[length][width] = figure[length][width];
			width++;
		}
		lst->figure[length][width] = '\0';
		free(figure[length]);
		length++;
	}
	free(figure);
	temp++;
}

void	cut_figure(char tetrimino[22], t_figure *lst)
{
	char	**figure;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	k = (5 * (lst->coords[0]) + (lst->coords[1]));
	figure = (char **)malloc(sizeof(char *) * lst->length);
	while (tetrimino[k] != '\0')
	{
		while (i < lst->length)
		{
			j = 0;
			figure[i] = (char *)malloc(sizeof(char) * (lst->width + 1));
			while (j != lst->width)
			{
				figure[i][j] = tetrimino[k];
				j++;
				k++;
			}
			figure[i][j] = '\0';
			i++;
			k = (5 * (lst->coords[0] + i) + (lst->coords[1]));
		}
		k++;
	}
	change_sharps(lst, figure);
}

int		get_length(char tetrimino[22], t_figure *lst)
{
	int first;
	int last;
	int i;
	int temp;
	int flag;

	i = 0;
	temp = 0;
	flag = 0;
	last = 0;
	while (tetrimino[i] != '\0')
	{
		if (tetrimino[i - 1] == '\n')
			temp++;
		if (tetrimino[i] == '#' && flag == 0)
		{
			first = temp;
			flag = 1;
		}
		if (tetrimino[i] == '#')
			last = temp;
		i++;
	}
	lst->coords[0] = first;
	return ((last - first) + 1);
}

int			get_width(char tetrimino[22], t_figure *lst)
{
	int last;
	int i;
	int temp;
	int flag;

	i = 0;
	temp = 0;
	flag = 0;
	last = 0;
	while (tetrimino[i] != '\0')
	{
		tetrimino[i - 1] == '\n' ? temp = 0 : 0;
		if (tetrimino[i] == '#' && flag == 0)
		{
			lst->coords[1] = temp;
			last = temp;
			flag = 1;
		}
		tetrimino[i] == '#' && lst->coords[1] > temp ? lst->coords[1] = temp : 0;
		tetrimino[i] == '#' && temp > last ? last = temp : 0;
		temp++;
		i++;
	}
	return ((last - lst->coords[1]) + 1);
}

void	start_cut(int fd)
{
	char		tetrimino[MAP_SIZE + 1];
	t_figure	*figures_lst;
	t_figure	*buff;
	int			ret;

	figures_lst = NULL;
	if (!figures_lst)
	{
		figures_lst = (t_figure *)malloc(sizeof(t_figure));
		figures_lst->next = NULL;
	}
	buff = figures_lst;
	while ((ret = read(fd, tetrimino, MAP_SIZE)) > 0)
	{
		tetrimino[ret] = '\0';
		figures_lst->width = get_width(tetrimino, figures_lst);
		figures_lst->length = get_length(tetrimino, figures_lst);
		cut_figure(tetrimino, figures_lst);
		figures_lst->next = (t_figure*)malloc(sizeof(t_figure));
		figures_lst = figures_lst->next;
	}
	ret == 0 ? figures_lst = NULL : 0;
	figures_lst = buff;
	solve_fill(figures_lst);
}
