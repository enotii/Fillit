/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:17:03 by caking            #+#    #+#             */
/*   Updated: 2019/02/02 23:43:03 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		if (ft_read_map(fd) == 1)
		{
		printf(GREEN("valid\n"));
		//ft_fill_it(fd);
		}
		else
		printf(PINK("error\n"));
	}
		close (fd);
	return (0);	
}