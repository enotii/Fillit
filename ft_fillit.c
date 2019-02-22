/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:07:02 by Alexandr          #+#    #+#             */
/*   Updated: 2019/02/22 21:06:26 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **map;

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
    count_tetr = count_tetr * 4;
	while (size * size < count_tetr)
		size++;
	return (size);
}

void free_map(char **map, int size)
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

void ft_maping(int size)
{
	int i;

	i = 0;
	map = (char **)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset((void *)map[i], '.', size);
		i++;
	}
	map[i] = NULL;
}

void find_place(int x, int y, t_figure *lst)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < lst->length)
	{
		j = 0;
		while (j < lst->width)
		{
			if ((lst->figure)[i][j] != '.' && (lst->figure)[i][j])
				map[y + i][x + j] = lst->figure[i][j];
			j++;
		}
		i++;
	}
}

int gogo_place(int x, int y, t_figure *lst)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < lst->length)
	{
		j = 0;
		while (j < lst->width)
		{
			if (map[y + i][x + j] != '.' && (lst->figure)[i][j] != '.'
				&& lst->figure[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_result(char **map)
{
	int	i;
 
	i = 0;
	while (map[i])
		{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
		}
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

int ft_sanya__ne_sdelal(t_figure *lst,int size)
{
    char **mapbuff;
    int begin;
    int begin2;

    begin2 = -1;
    while(++begin2 + lst->length <= size) 
    {
        begin = -1;
        while(++begin + lst->width <= size)
        {
            if (gogo_place(begin,begin2,lst))
            {
                mapbuff = ft_mapcpy(map);
                find_place(begin,begin2,lst);
            if(lst->next == NULL)
                return(ft_del(&mapbuff));
            if (ft_sanya__ne_sdelal(lst->next,size))
                return(ft_del(&mapbuff));
            map = mapbuff;
            }
        }    
    }
    return(0);
}

char **fill_it(t_figure *lst, int size)
{
    ft_maping(size);
    while(!(ft_sanya__ne_sdelal(lst,size)))
    {
        size++;
        free_map(map,size);
        ft_maping(size);
    }
    return (map);
}

void solve_fill(t_figure *lst)
{
    int size;
    int i;
    int j;

    i = 0;
    j = 0;
    size = optimal_size(lst);
    fill_it(lst,size);
    print_result(map);
}