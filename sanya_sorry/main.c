/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:32:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/11 17:39:05 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int ac, char **av)
{
	int fd;

	fd = open(av[ac- 1], O_RDONLY);
	if (ac == 2)
	{
		if (ft_read_map(fd) == 1)
		{
		close (fd);
		fd = open(av[ac - 1], O_RDONLY);
		ft_putstr(GREEN("valid\n"));
		print_figures(start_cut(fd));
		}
		else
		ft_putstr(PINK("error\n"));
	}
	else 
		ft_putstr("usage: fillit input_file\n");
		close (fd);
	return (0);	
}
