/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristinazueva <kristinazueva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 21:15:05 by kristinazue       #+#    #+#             */
/*   Updated: 2019/02/04 21:43:59 by kristinazue      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **result;

size_t	find_size(t_figure *tetriminos)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (tetriminos->next)
	{
		i++;
		tetriminos = tetriminos->next;
	}
	i = i * 4;
	while (j * j < i)
		j++;
		return (j);
}

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

int fill_it(t_figure *tetriminos, size_t size)
{
	int arr[4];
	char **mapbuff;

	arr[1] = -1;
	//fill_resolve(tetriminos, &arr[2], &arr[3]);

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

