/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristinazueva <kristinazueva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:10:54 by kristinazue       #+#    #+#             */
/*   Updated: 2019/02/06 15:17:02 by kristinazue      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	find_size(t_figure *tetriminos)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 2;
	while (tetriminos->next)
	{
		i++;
		tetriminos = tetriminos->next;
	}
	i = i * 4;
	while (j * j < i)
		j++;
	return (j);
}

void fill_map(t_figure *tetriminos, int *width, int *height)
{
    int i;

    i = 0;
    while ((tetriminos->figure)[i])
    {
        i++;
    }
    *height = i;
    *width = ft_strlen((tetriminos->figure)[i-1]);
}

char **ft_mapcpy(char **map)
{
    char **result;
    int i;

    i = 0;
    while(map[i])
        i++;
    result = (char **)malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (map[i])
    {
        result[i] = ft_strnew(ft_strlen(map[i]));
        ft_strcpy(*(result + i), *(map + i));
        i++;
    }
    result[i] = NULL;
    return (result);
}

int ft_del(char ***map)
{
    int i;

    i = 0;
    if (!map)
        return(0);
    while ((*map)[i])
    {
        free((*map)[i]);
        i++;
    }
    free(*map);
    return(1);
}

void	print_result(char **map)
{
	int	i;
    int j;

	i = 0;
	while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '.')
                printf(GREEN(" %c "), map[i][j]);
            else
                printf(PINK(" %c "), map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    	i = 0;
	i = 0;
	while (map[i])
		{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
		}
}