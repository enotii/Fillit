/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:07:02 by Alexandr          #+#    #+#             */
/*   Updated: 2019/02/14 21:47:15 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char   **create_map(t_figure *lst, int size)
{
    int             i;
    int             j;
    unsigned char            **map;
    i = 0;
    j = 0;
    map = (unsigned char **)malloc(sizeof(unsigned char *) * size);
    while (i != size)
    {
        map[i] = (unsigned char *)malloc(sizeof(unsigned char) * size + 1);
        while (j != size)
        {
            map[i][j] = 0;
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    return (map);
}

size_t  optimal_size(t_figure *figures_lst)
{
    size_t  count_tetr;
    size_t  size;
    int     alph;

    alph = 0;
    size = 0;
    count_tetr = 0;
    while (figures_lst->next != NULL)
    {
        figures_lst->alpha = alph + 65;
        count_tetr++;
        alph++;
        figures_lst = figures_lst->next;
    }
    size = size * 4;
	while (size * size < count_tetr - 1)
		size++;
	return (size);
}

int check_overlay(int size, unsigned char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i != size)
    {
        while (j != size)
        {
            if (map[i][j] > 90)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void delete_overlay(t_figure *lst, int size, unsigned char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i != size)
    {
        while (j != size)
        {
            if (map[i][j] > 90)
                map[i][j] = map[i][j] - lst->alpha;
            j++;
        }
        i++;
    }
}

void free_map(unsigned char **map, int size)
{
    int i;

    i = 0;
    while (i != size)
    {
         free(map[i]);
         i++;
    }
    free(map);
}

int fill_it(t_figure *lst, int size, int i, int j)
{
    unsigned char **map;
   
}

void solve_fill(t_figure *lst)
{
    int size;
    int i;
    int j;

    i = 0;
    j = 0;
    size = optimal_size(lst);
    fill_it(lst,size, i, j);
}