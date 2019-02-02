/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:17:03 by caking            #+#    #+#             */
/*   Updated: 2019/02/02 23:30:54 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
	int		fd;
	int		flag;

	flag = ac;
	fd = open(av[1], O_RDONLY);
	flag = ft_read_map(fd);
	if (flag == 0)
		printf(PINK("error\n"));
	else
	{
	//	ft_fill_it(fd);
		printf(GREEN("valid\t%d\n"), flag);
	}
		close (fd);
	return (0);	
}