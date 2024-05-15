/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 08:31:21 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/15 09:15:32 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "alg.h"
#include "datatypes.h"

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
		arrays[0][i]->content = obstacle;
		arrays[0][i]->next_x = NULL;
		arrays[0][i]->next_y = NULL;
		i++;
	}
	i = 0;
	while (i < y)
	{
		arrays[1][i] = malloc(sizeof(t_cell));
		arrays[1][i]->x = x;
		arrays[1][i]->y = i;
		arrays[1][i]->content = obstacle;
		arrays[1][i]->next_x = NULL;
		arrays[1][i]->next_y = NULL;
		i++;
	}
	return (arrays);
}

int	iterate_indexes(int *k, int *i, int *j, t_b_props *map_props)
{
	printf("inside iterate_indexes!\tk: %i, i: %i, j: %i\n", *k, *i, *j);
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
