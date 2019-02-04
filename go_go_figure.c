/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_go_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristinazueva <kristinazueva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:22:57 by kristinazue       #+#    #+#             */
/*   Updated: 2019/02/04 19:38:42 by kristinazue      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *fig_memmalloc(char *split, int begin_fig, int last_fig)
{
    char *str;
    int i;

    i = 0;
    str = (char *)malloc(last_fig - begin_fig + 3);
    while (begin_fig <= last_fig)
    {
        str[i] = split[i];
        i++;
        begin_fig++;
    }
    str[i] = '\n';
    str[++i] = '\0';
    return (str);
}

int fill_last_fig(char **split)
{
    int i;
    int j;
    int last_fig;

    i = 0;
    last_fig = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (split[j][i] == '#')
            {
                last_fig = i;
                break;
            }
            j++;
        }
        i++;
    }
    return (last_fig);
}

int fill_begin_fig(char **split)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (split[j++][i] == '#')
            return (i);
        }
        i++;
    }
    return (0);
}