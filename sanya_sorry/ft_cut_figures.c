/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:12:41 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/11 17:56:38 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**change_sharps(char **cuted, int w, int l)
{
	int			i;
	int			j;
	static int	temp;
	int			width;
	int			length;

	width = 0;
	length = 0;
	i = 0;
	j = 0;
	while (length != l)
	{
		while (width != w)
		{
			if (cuted[length][width] == '#')
				cuted[length][width] = temp + 65;
			width++;
		}
		length++;
	}
	temp++;
	return (cuted);
}

char	**cut_figure(char tetrimino[22], int w, int l, int *m[2])
{
	char	**figure;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	figure = (char **)malloc(sizeof(char *) * l);
	k = (5 * (*m[1])) + (*m[0]);
	while (tetrimino[k] != '\0')
	{
		while (i < l)
		{
			j = 0;
			figure[i] = (char *)malloc(sizeof(char) * w + 1);
			while (j != w)
			{
				figure[i][j] = tetrimino[k];
				j++;
				k++;
			}
			figure[i][j] = '\0';
			i++;
			k = (5 * (*m[1] + i) + (*m[0]));
		}
		k++;
	}
	return (change_sharps(figure, w, l));
}

int		get_length(char tetrimino[22], int *y)
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
	*y = first;
	return ((last - first) + 1);
}

int			get_width(char tetrimino[22], int *x)
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
			*x = temp;
			last = temp;
			flag = 1;
		}
		tetrimino[i] == '#' && *x > temp ? *x = temp : 0;
		tetrimino[i] == '#' && temp > last ? last = temp : 0;
		temp++;
		i++;
	}
	return ((last - *x) + 1);
}

t_figure	*start_cut(int fd)
{
	char		tetrimino[MAP_SIZE + 1];
	t_figure	*figures_lst;
	t_figure	*buff;
	int			ret;
	int			*coords[2];

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
		figures_lst->width = get_width(tetrimino, coords[0]);
		figures_lst->length = get_length(tetrimino, coords[1]);
		figures_lst->figure = cut_figure(tetrimino, \
		figures_lst->width, figures_lst->length, coords);
		figures_lst->next = (t_figure*)malloc(sizeof(t_figure));
		figures_lst = figures_lst->next;
	}
	ret == 0 ? figures_lst = NULL : 0;
	figures_lst = buff;
	return (figures_lst);
}

void print_figures(t_figure *figures_lst)
{
	int i;

	while (figures_lst->next)
	{
		i = 0;
		while(i < figures_lst->length)
		{
			ft_putendl(figures_lst->figure[i]);
		//	ft_putchar('\n');
			i++;
		}
		figures_lst = figures_lst->next;
	}
}