/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfrnt_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:33:32 by caking            #+#    #+#             */
/*   Updated: 2019/02/26 21:29:42 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **g_map;

int			ft_del(char ***g_map)
{
	int		i;

	i = 0;
	if (!g_map)
		return (0);
	while ((*g_map)[i])
	{
		free((*g_map)[i]);
		i++;
	}
	free(*g_map);
	return (1);
}

void		print_result(int size, char map[size][size])
{
	int	i;
	int j;

	i = 0;
	while (i != size)
	{
		j = 0;
		while (j != size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		ft_mapcpy(int size, char map[size][size + 1], char mb[size][size])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i != size)
	{
		j = 0;
		while (j != size)
		{
			mb[i][j] = map[i][j];
			j++;
		}
		i++;
	}
}

void		ft_maping(int size, char map[size][size])
{
	int		i;
	int 	j;

	i = 0;
	while (i != size)
	{
		j = 0;
		while (j != size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		free_map(char **g_map, int size)
{
	int		i;

	i = 0;
	while (i != size)
	{
		free(g_map[i]);
		i++;
	}
	free(g_map);
}
