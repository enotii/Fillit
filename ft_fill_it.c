/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristinazueva <kristinazueva@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:22:04 by caking            #+#    #+#             */
/*   Updated: 2019/02/05 14:07:49 by kristinazue      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_split(char *buff)
{
    char	**split;
	int		i;
	int		size;

	i = 0;
	split = ft_strsplit(buff, '\n');
    while (ft_empty(split[i]) && i < 4)
        i++;
    size = i;
    while (!ft_empty(split[size]) && size < 4)
		size++;
    ft_strclr(buff); //str = '\0'
    while (i < size)
    {
        ft_strcat(buff, (fig_memmalloc(split[i], fill_begin_fig(split),fill_last_fig(split))));
		i++;
    }
}
int ft_empty(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i++] == '#')
        return (0);
    }
    return (1);
}

void change_letters(char **split, char ch)
{
    int i;
    int j;

    i = 0;
    while (split[i])
    {
        j = 0;
        while (split[i][j] != '\0')
        {
            if (split[i][j] == '#')
            split [i][j] = ch;
            j++;
        }
        i++;
    }
}

void ft_fill_parsing(t_figure **result, char buff[21], char ch)
{
    char **split;

    ft_split(buff);
    split = ft_strsplit(buff, '\n');
    change_letters(split, ch);
    fill_list(result, &split);
}

t_figure *ft_fill_read(int fd, t_figure *result)
{
    char buff[21];
    int i;
    int j;
    char ch;

    ch = 'A';
    i = 0;
    while(1 && !(j = 0))
    {
        if ((i = read(fd, buff, 21)) == 21)
            j = 1;
        if ((i == 20 || i == 21) && !(buff[20] = 0))
            ft_fill_parsing(&result, buff, ch++);
    }
    return (result);
}