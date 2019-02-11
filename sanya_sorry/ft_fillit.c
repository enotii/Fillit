/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:07:02 by Alexandr          #+#    #+#             */
/*   Updated: 2019/02/09 16:32:46 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void create_map(t_figure *figures_lst)
{
    static int  temp;
    char        **map;
    int         i;
    int         j;
    int         size;

    size = temp + 2;
    i = 0;
    j = 0;
    map = (char **)malloc(sizeof(char *) * size);
    while (i != size)
    {
        map[i] = (char *)malloc(sizeof(char) * size);
        i++;
    }
    i = 0;
    while (i != size)
    {
        while (j != size)
        {
            map[i][j] = '0';
            j++;
        }
        i++;
    }
    temp++;
    paste_figures(figures_lst, map, size);
}

void delete_map(char **map, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i != size)
    {
        while (j != size)
        {
            free(map[i][j]);
            j++;
        }
        free(map[i]);
        i++;
    }
}

int check_overlay(char **map, int size)
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
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void save_prev(char **map, int size, int flag, int right, int bot)
{
    static char **prev_map;
    static int  prev_size;
    static int  prev_right;
    static int  prev_bot;
    
    if (flag == 0)
    {
        prev_size = size;
        prev_map = map;
        prev_right = right;
        prev_bot = bot;
    }
    else
    {
        map = prev_map;
        size = prev_size;
        right = prev_right;
        bot = prev_bot;
    }
}

int paste_figures(t_figure *figures_lst, char **map, int size)
{
    static int  right;
    static int  bot;
    char        **prev_map;
    int         i;
    int         j;

    while (figures_lst->next)
    {
        i = 0;
        j = 0;
        save_prev(map, size, 0, right, bot);
        while(i != figures_lst->length)
        {
            while (j != figures_lst->width)
            {
                map[i + bot][j + right] += figures_lst->figure[i][j];
                j++;
            }
            i++;
        }
        if (check_overlay(map, size) == 0)
        {
            if (right != size)
                right++;
            if (right == size && bot != bot)
                bot++;
            if (right == size && bot == size)
            {
                save_prev(map, size, 1, right, bot);
            }
            paste_figures(figures_lst, map, size);
        }
        figures_lst = figures_lst->next;
    }
}