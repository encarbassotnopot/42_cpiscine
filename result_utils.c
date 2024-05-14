/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bernat_test2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:05:10 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/14 18:43:03 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "alg.h"

int	iterate_indexes(int *k, int *i, int *j, t_b_props *map_props)
{
	//printf("inside iterate_indexes!\tk: %i, i: %i, j: %i\n", *k, *i, *j);
	(*i)--;
	(*j)--;
	if (*i >= 0 && *j >= 0)
		return (1);
	(*k)++;
	if (*k < (map_props->size_y + map_props->size_x - 1))
	{
		if (*k < map_props->size_y)
		{
			*i = map_props->size_x - 1;
			*j = *k;
		}
		else
		{
			*i = map_props->size_x - 2 - *k + map_props->size_y;
			*j = map_props->size_y - 1;
		}
		return (1);
	}
	return (0);
}

int get_max_square(int x, int y, t_cell ***arrays)
{
	int next_x;
	int next_y;
	//int min;

	next_x = get_dist(y, x, 'v', arrays);
	next_y = get_dist(x, -y, 'h', arrays);
	if (next_x > next_y)
		return (next_y);
	return (next_x);
}

int	get_max_square_full(int x, int y, t_cell ***arrays, char *dir)
{
	int max_h;
	int max_v;

	max_h = get_max_square(x + 1, y, arrays);
	max_v = get_max_square(x, y - 1, arrays);
	printf("get_max_square_full\n");
	if (max_h >= max_v)
	{
		*dir = 'h';
		return (max_h);
	} else
	{
		*dir = 'v';
		return (max_v);
	}
}

t_result	*get_result(t_b_props *map_props, t_cell **map, t_cell ***arrays)
{
	int			i;
	int			j;
	int			k;
	int			size;
	char		dir;
	t_result	*res;

	res = malloc(sizeof(t_result));
	k = -1;
	i = 0;
	j = 0;
	dir = 0;
	while (iterate_indexes(&k, &i, &j, map_props) == 1)
	{
		if (get_cell_value(map, i, j) == 1)
		{
			printf("k: %i, i: %i, j: %i\n", k, i, j);
			size = get_max_square_full(i, j, arrays, &dir);
			//append_me(t_cell[i][j], arrays);
			if (size > res->size || (size == res->size && i > res->x))
				update_result(res, size, &map[i][j], dir);
		}
	}
	printf("square size = %i", res->size);
	return (res);
}
