/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 21:54:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/03/05 23:20:09 by gachibass22      ###   ########.fr       */
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
	if (bn == 5 || bn == 4)
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

int	ft_check_strings(char *map)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (map[i] != '\0' && i < 19)
	{
		if (map[i] == '\n')
		{
			if (len < 4 || len > 4)
				return (0);
			len = -1;
		}
		len++;
		i++;
	}
	return (1);
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
	if (ft_check_strings(map) == 1)
		return (ft_check_symbols(dot, sharp, bn, map));
	return (0);
}

int	ft_read_map(int fd)
{
	char	map[MAP_SIZE + 1];
	int		ret;
	int		flag;
	char	*buff;
	int		count;

	count = 0;
	flag = 0;
	if (fd < 0)
		return (0);
	while ((ret = read(fd, map, MAP_SIZE)) > 0)
	{
		buff != NULL ? free(buff) : 0;
		flag++;
		map[ret] = '\0';
		if ((map[0] == '\0') || ft_count_symbs(map) != 1)
			return (0);
		buff = ft_strdup((const char *)map);
		count++;
	}
	if (ret == 0 && buff != NULL)
		return (bn_counter(buff));
	if ((ret == 0 && flag == 0) || flag > 26)
		return (0);
	return (flag);
}
