/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bernat_test2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:05:10 by bcanals-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/15 09:21:33 by bcanals-         ###   ########.fr       */
=======
/*   Updated: 2024/05/14 19:32:04 by bcanals-         ###   ########.fr       */
>>>>>>> bsq/m
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
#include "alg.h"

<<<<<<< HEAD
int	get_max_square(int x, int y, t_cell ***arrays)
{
	int	next_x;
	int	next_y;

	printf("inside get_max_square");
	next_x = get_dist(y, x, 'h', arrays);
	next_y = get_dist(x, -y, 'v', arrays);
	printf(" - leaving get_max_square\n");
=======
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

	next_x = get_dist(y, x, 'h', arrays);
	printf("next_x = %i, ", next_x);
	next_y = get_dist(x, -y, 'v', arrays);
	printf("next_y = %i\n", next_y);
>>>>>>> bsq/m
	if (next_x > next_y)
		return (next_y);
	return (next_x);
}

<<<<<<< HEAD
int	is_better(int i, int j, int size, t_result *res)
{
	printf("inside is_better\n");
	if (size > res->size)
		return (1);
	if (size == res->size && j > res->y)
		return (1);
	if (size == res->size && j == res->y && i < res->x)
		return (1);
	return (0);
}

int	check_max_square(t_point pos, int *count, t_cell ***arrays, int goal)
{
	int	next_x;
	int	next_y;
	int	min;

	printf("inside chech_max_square");
	next_x = get_dist(pos.y, pos.x, 'h', arrays);
	next_y = get_dist(pos.x, -pos.y, 'v', arrays);
	printf("next_x = %i, next_y = %i\n", next_x, next_y);
	printf("pos.x = %i, pos.y = %i\n", pos.x, pos.y);
	if (next_x > next_y)
		min = next_y;
	else
		min = next_x;
	printf("min = %i, goal = %i, count = %i\n", min, goal, *count);
	if (min >= 1)
		(*count)++;
	if (min <= 1 || (goal == 1 && min > 1))
	{
		printf(" - leaving chech_max_square\n");
		return (*count);
	}
	if (min < goal)
		goal = min;
	check_max_square((t_point){pos.x + 1, pos.y - 1}, count, arrays, goal - 1);
	printf(" - leaving chech_max_square\n");
	return (*count);
}

int	check_max(int x, int y, t_cell ***arrays, t_result *res)
{
	int	size;
	int	count;

	printf("inside check_max");
	count = 0;
	size = get_max_square(x, y, arrays);
	printf("size = %i", size);
	if (size > 1)
		size = check_max_square((t_point){x, y}, &count, arrays, size);
	if (is_better(x, y, size, res) == 1)
	{
		res->x = x;
		res->y = y;
		res->size = size;
	}
	printf(" - leaving check_max\n");
	return (size);
=======
int	get_max_square_full(int x, int y, t_cell ***arrays, char *dir)
{
	int max_h;
	int max_v;

	max_h = get_max_square(x + 1, y, arrays);
	max_v = get_max_square(x, y - 1, arrays);
	if (max_h >= max_v)
	{
		*dir = 'h';
		return (max_h);
	} else
	{
		*dir = 'v';
		return (max_v);
	}
>>>>>>> bsq/m
}

t_result	*get_result(t_b_props *map_props, t_cell **map, t_cell ***arrays)
{
	int			i;
	int			j;
	int			k;
	int			size;
<<<<<<< HEAD
=======
	char		dir;
>>>>>>> bsq/m
	t_result	*res;

	res = malloc(sizeof(t_result));
	k = -1;
	i = 0;
	j = 0;
<<<<<<< HEAD
	while (iterate_indexes(&k, &i, &j, map_props) == 1)
	{
		printf("i: %i, j: %i\n", i, j);
		if (get_cell_value(map, i, j) == 1)
		{
			append_me(i, j, arrays);
			printf("just appended\n");
			print_arrays(arrays, map_props);
		}
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
=======
	dir = 0;
	while (iterate_indexes(&k, &i, &j, map_props) == 1)
	{
		if (get_cell_value(map, i, j) == 1)
		{
			printf("k: %i, i: %i, j: %i\n", k, i, j);
			size = get_max_square_full(i, j, arrays, &dir);
			printf("max_square = %i\n", size);
			//append_me(t_cell[i][j], arrays);
			if (size > res->size || (size == res->size && i > res->x))
				update_result(res, size, &map[i][j], dir);
		}
	}
	printf("ANSWER: %i", res->size);
>>>>>>> bsq/m
	return (res);
}
