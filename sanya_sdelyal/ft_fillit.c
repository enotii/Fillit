/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:07:02 by Alexandr          #+#    #+#             */
/*   Updated: 2019/02/13 19:26:52 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    create_map(t_figure *lst, int size, char **map)
{
    int             i;
    int             j;

    i = 0;
    j = 0;
    map = (char **)malloc(sizeof(char *) * size);
    while (i != size)
    {
        map[i] = (char *)malloc(sizeof(char) * size + 1);
        while (j != size)
        {
            map[i][j] = 46;
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
}

size_t  optimal_size(t_figure *figures_lst)
{
    size_t  count_tetr;
    size_t  size;
    int     alph;

    alph = 0;
    size = 0;
    count_tetr = 0;
    while (figures_lst->next)
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

int check_overlay(int size, char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i != size)
    {
        while (j != size)
        {
            if (map[i][j] - 46 > 90)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void delete_overlay(t_figure *lst, int size, char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i != size)
    {
        while (j != size)
        {
            if (map[i][j] > 90 || map[i][j] == lst->alpha)
                map[i][j] = map[i][j] - lst->alpha;
            j++;
        }
        i++;
    }
}

int fill_map(t_figure *lst, int size,char **map)
{
    int i;
    int j;
    int x;
    int y;
    static int right;
    static int bot;
    int temp;
    
    temp = 0;
    i = 0;
    y = 0;
    while (i < size && lst->length <= size)
    {
        j = 0;
        x = 0;
        while (j < size && lst->width <= size)
        {
            map[i + bot][j + right] += lst->figure[y][x];
            j++;
            x++;
        }
        map[i][j] = '\0';
        i++;
        y++;
    }
    if (size < lst->width || size < lst->length)
    {   
        size++;
        while (temp < size)
        {
            map[temp][size] = 0;
            temp++;
        }
        temp = 0;
        while (temp < size)
        {
            map[size][temp] = 0;
            temp++;
        }
        fill_map(lst, size, map);
    }
    if (check_overlay(size, map) == 1)
    {
        delete_overlay(lst, size, map);
        create_map(lst, size, map);
        if (j + lst->width != size)
        {
            right++;
            fill_map(lst, size, map);
        }
        else if (j + lst->width == size && i + lst->width != size)
        {
            bot++;
            right = 0;
            fill_map(lst,size, map);
        }
        else if (j + lst->width == size && i + lst->width == size)
        {
            size++;
            create_map(lst, size, map);
            right = 0;
            bot = 0;
            fill_map(lst, size, map);
        }
        fill_map(lst, size, map);
    }
    lst = lst->next;
    fill_map(lst, size, map);
    return (size);
}

void   solve_fill(t_figure *lst)
{
    int size;
    int i;
    int j;
    char **map;

    i = 0;
    j = 0;
    size = optimal_size(lst);
    create_map(lst, size, map);
    fill_map(lst, size, map);
    while (i != size)
    {
        while (j != size)
        {
            ft_putchar(map[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}