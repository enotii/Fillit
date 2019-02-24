/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:07:02 by Alexandr          #+#    #+#             */
/*   Updated: 2019/02/24 21:40:14 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **g_map;

void		find_place(int x, int y, t_figure *lst)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < lst->length)
	{
		j = 0;
		while (j < lst->width)
		{
			if ((lst->figure)[i][j] != '.' && (lst->figure)[i][j])
				g_map[y + i][x + j] = lst->figure[i][j];
			j++;
		}
		i++;
	}
}

int			gogo_place(int x, int y, t_figure *lst)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < lst->length)
	{
		j = 0;
		while (j < lst->width)
		{
			if (g_map[y + i][x + j] != '.' && (lst->figure)[i][j] != '.'
				&& lst->figure[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_sanya__ne_sdelal(t_figure *lst, int size)
{
	int		begin;
	int		begin2;
	char	**mapbuff;

	begin2 = -1;
	while (++begin2 + lst->length <= size)
	{
		begin = -1;
		while (++begin + lst->width <= size)
		{
			if (gogo_place(begin, begin2, lst))
			{
				mapbuff = ft_mapcpy(g_map);
				find_place(begin, begin2, lst);
				if (lst->next == NULL)
					return (ft_del(&mapbuff));
				if (ft_sanya__ne_sdelal(lst->next, size))
					return (ft_del(&mapbuff));
				g_map = mapbuff;
			}
		}
	}
	return (0);
}

char		**fill_it(t_figure *lst, int size)
{
	ft_maping(size);
	while (!(ft_sanya__ne_sdelal(lst, size)))
	{
		size++;
		free_map(g_map, size);
		ft_maping(size);
	}
	return (0);
}

void		solve_fill(t_figure *lst)
{
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = optimal_size(lst);
	fill_it(lst, size);
	print_result(g_map);
}
