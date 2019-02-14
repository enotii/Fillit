/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:32:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/14 15:42:19 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_figures(t_figure *lst)
{
	int i;

	while (lst->next)
	{
		i = 0;
		while (i < lst->length)
		{
			ft_putstr(lst->figure[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		lst = lst->next;
	}
}

int main (int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	start_cut(fd);
	return (0);	
}