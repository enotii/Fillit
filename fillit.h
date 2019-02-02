/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caking <caking@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:27:36 by mbeahan           #+#    #+#             */
/*   Updated: 2019/02/02 23:31:04 by caking           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define MAP_SIZE 21
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# define PINK(x) "\033[35;1m" x "\033[0m"
# define GREEN(x) "\033[32;1m" x "\033[0m"

int ft_read_map(int fd);
void ft_fill_it(int fd);

#endif