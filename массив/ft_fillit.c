/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:07:02 by Alexandr          #+#    #+#             */
/*   Updated: 2019/02/26 21:35:53 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		find_place(int coords[2], t_figure *lst, int size, char map[size][size])
{
	register int	i;
	register int	j;
	int				x;
	int				y;

	x = coords[1];
	y = coords[0];
	i = 0;
	while (i < lst->length)
	{
		j = 0;
		while (j < lst->width)
		{
			if ((lst->figure)[i][j] != '.' && (lst->figure)[i][j])
				map[y + i][x + j] = lst->figure[i][j];
			j++;
		}
		i++;
	}
}

int			gogo_place(int coords[2], t_figure *lst, int size, char map[size][size])
{
	register int	i;
	register int	j;
	int				x;
	int				y;

	x = coords[1];
	y = coords[0];
	i = 0;
	while (i < lst->length)
	{
		j = 0;
		while (j < lst->width)
		{
			if (map[y + i][x + j] != '.' && (lst->figure)[i][j] != '.'
				&& lst->figure[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_sanya__ne_sdelal(t_figure *lst, int size, char map[size][size])
{
	int		coords[2];
	char	mapbuff[size][size];

	coords[0] = -1;
	while (++coords[0] + lst->length <= size)
	{
		coords[1] = -1;
		while (++coords[1] + lst->width <= size)
		{
			if (gogo_place(coords, lst, size, map))
			{
				ft_mapcpy(size, map, mapbuff);
				find_place(coords, lst, size, map);
				if (lst->next == NULL)
					return (1);
				if (ft_sanya__ne_sdelal(lst->next, size, map))
					return (1);
				map = mapbuff;
			}
		}
	}
	return (0);
}

int			fill_it(t_figure *lst, int size)
{
	char map[size][size];

	while (!(ft_sanya__ne_sdelal(lst, size, map)))
	{
		size++;
		ft_maping(size, map);
	}
	print_result(size, map);
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
}
