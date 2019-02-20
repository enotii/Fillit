/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:32:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/20 21:33:52 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int ac, char **av)
{
	int		fd;

	fd = open(av[ac - 1], O_RDONLY);
	if (ac == 2)
	{
		if (ft_read_map(fd) == 1)
		{
			close (fd);
			fd = open(av[ac - 1], O_RDONLY);
			start_cut(fd);
		}
		else
		ft_putstr("error\n");
	}
	return (0);
}