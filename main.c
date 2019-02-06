/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristinazueva <kristinazueva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:17:03 by caking            #+#    #+#             */
/*   Updated: 2019/02/06 14:21:34 by kristinazue      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	int		fd;
	t_figure *result;

	fd = open(av[ac - 1], O_RDONLY);
	result = NULL;
	if (ac == 2)
	{
		if (ft_read_map(fd) == 1)
		{
		close (fd);
		fd = open(av[ac - 1], O_RDONLY);
		ft_putstr(GREEN("valid\n"));
		print_result(fill_cycle(ft_fill_read(fd,result)));
		}
		else
		ft_putstr(PINK("error\n"));
	}
	else 
		ft_putstr("usage: fillit input_file\n");
		close (fd);
	return (0);	
}