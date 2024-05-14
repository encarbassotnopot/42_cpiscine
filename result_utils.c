/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bernat_test2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:05:10 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/15 01:25:44 by bcanals-         ###   ########.fr       */
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

	next_x = get_dist(y, x, 'h', arrays);
	next_y = get_dist(x, -y, 'v', arrays);
	if (next_x > next_y)
		return (next_y);
	return (next_x);
}

int	is_better(int i, int j, int size, t_result *res)
{
	if (size > res->size)
		return (1);
	if (size == res->size && j > res->y)
		return (1);
	if (size == res->size && j == res->y && i < res->x)
		return (1);
	return (0);
}

int check_max_square(t_point pos, int *count, t_cell ***arrays, int goal)
{
	int next_x;
	int next_y;
	int min;
	
	next_x = get_dist(pos.y, pos.x, 'h', arrays);
	next_y = get_dist(pos.x, -pos.y, 'v', arrays);
	if (next_x > next_y)
		min = next_y;
	else
		min = next_x;
	if (min >= 1)
		(*count)++;
	if (min <= 1 || (goal == 1 && min > 1))
	{
		return (*count);
	}
	if (min < goal)
		goal = min;
	check_max_square((t_point){pos.x + 1, pos.y - 1}, count, arrays, goal - 1);
	return (*count);
}

int	check_max(int x, int y, t_cell ***arrays, t_result *res)
{
	int size;
	int count;

	count = 0;
	size = get_max_square(x, y, arrays);
	if (size > 1)
		size = check_max_square((t_point){x, y}, &count, arrays, size);
	if (is_better(x, y, size, res) == 1)
	{
		res->x = x;
		res->y = y;
		res->size = size;
	}
	return (size);
}

t_result	*get_result(t_b_props *map_props, t_cell **map, t_cell ***arrays)
{
	int			i;
	int			j;
	int			k;
	int			size;
	t_result	*res;

	res = malloc(sizeof(t_result));
	k = -1;
	i = 0;
	j = 0;
	while (iterate_indexes(&k, &i, &j, map_props) == 1)
	{
		if (get_cell_value(map, i, j) == 1)
			append_me(i, j, arrays);
		else
		{
			if (i == map_props->size_x - 1 || j == 0)
				size = 1;
			else
				size = get_max_square(i, j, arrays);
			if (is_better(i, j, size, res) == 1)
				check_max(i, j, arrays, res);
		}
	}
	printf("RESULT: %ix%i\n\tx: %i, y: %i", res->size, res->size, res->x, res->y);
	return (res);
}
