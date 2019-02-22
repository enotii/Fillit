/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:40:53 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/22 21:08:48 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int ac, char **av)
{
    int fd;

    fd = open(av[ac - 1], O_RDONLY);
  	if (ac == 2)
	{
		if (ft_read_map(fd))
		{
			close (fd);
			fd = open(av[ac - 1], O_RDONLY);
			start_cut(fd);
		}
		else
		ft_putstr("error\n");
	}
    else
	ft_putstr("usage: fillit input_file\n");    
    close(fd);
    return (0);
}