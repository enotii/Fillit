/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:32:56 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/01 18:56:04 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int ac, char **av)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	printf("%d", ft_read_map(fd));
	return (0);	
}
