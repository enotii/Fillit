/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfrnt_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 21:33:32 by caking            #+#    #+#             */
/*   Updated: 2019/02/24 22:00:32 by caking           ###   ########.fr       */
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

void		print_result(char **g_map)
{
	int	i;

	i = 0;
	while (g_map[i])
	{
		ft_putstr(g_map[i]);
		ft_putchar('\n');
		i++;
	}
}

char		**ft_mapcpy(char **g_map)
{
	char	**result;
	int		i;

	i = 0;
	while (g_map[i])
		i++;
	result = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (g_map[i])
	{
		result[i] = ft_strnew(ft_strlen(g_map[i]));
		ft_strcpy(*(result + i), *(g_map + i));
		i++;
	}
	result[i] = NULL;
	return (result);
}

void		ft_maping(int size)
{
	int		i;

	i = 0;
	g_map = (char **)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		g_map[i] = ft_strnew(size);
		ft_memset((void *)g_map[i], '.', size);
		i++;
	}
	g_map[i] = NULL;
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
