/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 21:15:05 by kristinazue       #+#    #+#             */
/*   Updated: 2019/02/11 14:19:16 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **result;

void ft_maping(size_t size)
{
	size_t i;

	i = 0;
	result = (char **)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		result[i] = ft_strnew(size);
		ft_memset((void *)result[i], '.', size); //поле точками
		i++;
	}
	result[i] = NULL;
}

int go_go_place(int x, int y, t_figure *tetriminos)
{
	register int	i;
	register int	j;
	int				width;
	int				height;

	fill_map(tetriminos, &width, &height);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (result[y + i][x + j] != '.' && (tetriminos->figure)[i][j] != '.'
				&& tetriminos->figure[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void find_place(int x, int y, t_figure *tetriminos)
{
	register int	i;
	register int	j;
	int				width;
	int				height;

	i = 0;
	fill_map(tetriminos, &width, &height);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((tetriminos->figure)[i][j] != '.' && (tetriminos->figure)[i][j])
				result[y + i][x + j] = tetriminos->figure[i][j];
			j++;
		}
		i++;
	}
}


int fill_it(t_figure *tetriminos, size_t size)
{
	int arr[4];
	char **mapbuff;

	arr[1] = -1;
	fill_map(tetriminos, &arr[2], &arr[3]);
	while (++arr[1] + arr[3] <= (int)size)
	{
		arr[0] = -1;
		while (++arr[0] + arr[2] <= (int)size)
		{
			if (go_go_place(arr[0], arr[1], tetriminos))
			{
				mapbuff = ft_mapcpy(result);
				find_place(arr[0], arr[1], tetriminos);
				if (tetriminos->next == NULL)
					return (ft_del(&mapbuff));
				if (fill_it(tetriminos->next, size))
					return (ft_del(&mapbuff));
				result = mapbuff;
			}
	
	print_result(result);
	getchar();
    system("clear");
		}
	}
	return(0);
}

char **fill_cycle(t_figure *tetriminos)
	{
		size_t size;

		size = find_size(tetriminos);
		ft_maping(size);
		while (!fill_it(tetriminos,size))
		{
			size++;
			free(result);
			ft_maping(size);
		}
		return (result);
	}