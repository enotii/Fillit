/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfrnt_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 22:00:04 by caking            #+#    #+#             */
/*   Updated: 2019/02/24 22:03:27 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			bn_counter(char *buff)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	free(buff);
	if (count != 4)
		return (0);
	return (1);
}

size_t		optimal_size(t_figure *figures_lst)
{
	int		alph;
	size_t	count_tetr;
	size_t	size;

	alph = 0;
	size = 0;
	count_tetr = 0;
	while (figures_lst->next)
	{
		figures_lst->alpha = alph + 65;
		count_tetr++;
		alph++;
		figures_lst = figures_lst->next;
	}
	count_tetr = count_tetr * 4;
	while (size * size < count_tetr)
		size++;
	return (size);
}
