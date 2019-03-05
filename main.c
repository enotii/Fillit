/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachibass228 <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:40:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/03/05 23:22:22 by gachibass22      ###   ########.fr       */
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
	char	alph;
	size_t	count_tetr;
	size_t	size;

	alph = 'A';
	size = 2;
	count_tetr = 0;
	while (figures_lst->next)
	{
		figures_lst->alpha = alph + 65 - 'A';
		count_tetr++;
		alph++;
		figures_lst = figures_lst->next;
	}
	count_tetr = count_tetr * 4;
	while (size * size < count_tetr)
		size++;
	return (size);
}

void free_list(t_figure *figures_lst)
{
	int i;

	i = 0;
	while (i < figures_lst->length)
	{
		free(figures_lst->figure[i]);
		++i;
	}
	free(figures_lst->figure);
	free(figures_lst);
}

int			main(int ac, char **av)
{
	int		fd;
	
	fd = open(av[ac - 1], O_RDONLY);
	if (ac == 2)
	{
		if (ft_read_map(fd))
		{
			close(fd);
			fd = open(av[ac - 1], O_RDONLY);
			start_cut(fd);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: fillit input_file\n");
	close(fd);
	exit(0);
}
