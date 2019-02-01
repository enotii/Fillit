/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 21:13:52 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/01 21:14:51 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_figures(char *map)
{
	int contacts;
	int i;

	i = 0;
	contacts = 0;
	while (map[i])
	{
		if (map[i] == '#' && map[i - 5] == '#')
			contacts++;
		if (map[i] == '#' && map[i + 5] == '#')
			contacts++;
		if (map[i] == '#' && map[i - 1] == '#')
			contacts++;
		if (map[i] == '#' && map[i + 1] == '#')
			contacts++;
		i++;
	}
	if (contacts == 6 || contacts == 8)
		return (1);
	return (0);
}

int	ft_check_symbols(int dot, int sharp, int bn, char *map)
{
	int i;

	i = 0;
	if (bn == 4 || bn == 5)
	{
		if (dot == 12 && sharp == 4)
		{
			while (map[i])
			{
				if (!(map[i] == '\n' || map[i] == '.' || map[i] == '#'))
					return (0);
				i++;
			}
			if (ft_check_figures(map) == 1)
				return (1);
		}
	}
	return (0);
}

int	ft_count_symbs(char *map)
{
	int i;
	int	sharp;
	int	dot;
	int	bn;

	i = 0;
	sharp = 0;
	dot = 0;
	bn = 0;
	while (map[i])
	{
		if (map[i] == '.')
			dot++;
		if (map[i] == '#')
			sharp++;
		if (map[i] == '\n')
			bn++;
		if (map[i] != '\n' && map[i] == '.' && map[i] == '#')
			return (0);
		i++;
	}
	return (ft_check_symbols(dot, sharp, bn, map));
}

int	ft_read_map(int fd)
{
	char	map[MAP_SIZE + 1];
	int		ret;
	int		flag;

	flag = 0;
	if (fd < 0)
		return (0);
	while ((ret = read(fd, map, MAP_SIZE)) > 0)
	{
		map[ret] = '\0';
		if (map[0] == '\0')
			return (0);
		if (ft_count_symbs(map) != 1)
			return (0);
		flag++;
	}
	if (ret == 0 && flag == 0)
		return (0);
	return (1);
}
