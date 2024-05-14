/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:03:39 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/14 18:50:01 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>

void	update_result(t_result *res, int size, t_cell *obs, char dir)
{
	res->size = size;
	res->x = obs->x;
	res->y = obs->y;
	if (dir == 'v')
		res->x += 1;
	else if (dir == 'h')
		res->y -= 1;
	return ;
}

t_cell	*get_next_cell(t_cell *cell, char dir)
{
	if (dir == 'h')
		return (cell->next_x);
	if (dir == 'v')
		return (cell->next_y);
	else
		return NULL;
}

int	get_param(t_cell *cell, char dir)
{
	if (dir == 'h')
		return (cell->x);
	if (dir == 'v')
	{
		if (cell->y == -1)
			return (-1);
		return (-cell->y);
	}
	else
		return -1;
}

t_cell *get_obst(int coord, char dir, t_cell ***arrays)
{
	if (dir == 'h')
		return(arrays[1][coord]);
	if (dir == 'v')
		return(arrays[0][coord]);
	else
		return NULL;
}

int get_dist(int coord, int val, char dir, t_cell ***arrays)
{
	int		dist;
	t_cell	*obst;

	printf("get_dist_1\n");
	obst = get_obst(coord, dir, arrays);
	printf("get_dist_2\n");
	while (get_param(obst, dir) < val)
	{
		printf("get_dist_2.1\n");
		obst = get_next_cell(obst, dir);
	}
	printf("get_dist_3\n");
	dist = val - get_param(obst, dir);
	printf("get_dist_4\n");
	if (dist < 0)
		dist *= -1;
	return (dist);
}

t_cell	***set_cell_array(int x, int y)
{
	t_cell	***arrays;
	int		i;

	arrays = malloc(2 * sizeof(t_cell **));
	arrays[0] = malloc(x * sizeof(t_cell *));
	arrays[1] = malloc(y * sizeof(t_cell *));
	i = 0;
	while (i < x)
	{
		arrays[0][i] = malloc(sizeof(t_cell));
		arrays[0][i]->x = i;
		arrays[0][i]->y = -1;
		arrays[0][0]->content = obstacle;
		i++;
	}
	i = 0;
	while (i < y)
	{
		arrays[1][i] = malloc(sizeof(t_cell));
		arrays[1][i]->x = x;
		arrays[1][i]->y = i;
		arrays[1][i]->content = x;
		i++;
	}
	return (arrays);
}
