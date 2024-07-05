/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:03:39 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/15 10:30:52 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>

void	print_arrays(t_cell ***arrays, t_b_props *map)
{
	int	i = 0;
	int j = 0;
	t_cell *cell;

	printf("-----------------------------\n");
	while (i < 2)
	{
		while ((i == 0 && j < map->size_x) || (i == 1 && j < map->size_y))
		{
			printf("flag 1\n");
			cell = arrays[i][j];
			while (i >= 0)
			{
				printf("position %i, %i\tcont = %i\n", cell->x, cell->y, cell->content);
				printf("next cells%p, %p\n", (void*)arrays[i][j]->next_x, (void*)arrays[i][j]->next_y);
				if (arrays[i][j]->next_x == NULL)
					break;
				cell = cell->next_x;
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("-----------------------------\n");
}
void	append_me(int x, int y, t_cell ***arrays)
{
	t_cell	*temp;
	t_cell	*p_t_x;
	t_cell	*p_t_y;

	p_t_x= arrays[0][x];
	p_t_y= arrays[1][y];
	printf("p_t_x = %p\t", (void*)p_t_x);
	printf("p_t_y = %p\n", (void*)p_t_y);
	temp = malloc(sizeof(t_cell));
	printf("->temp = %p\n", (void*)temp);
	temp->x = x;
	temp->y = y;
	temp->content = obstacle;
	temp->next_x = arrays[0][x];
	temp->next_y = arrays[1][y];
	printf("temp->next_x = %p\t", (void*)temp->next_x);
	printf("temp->next_y = %p\n", (void*)temp->next_y);
	arrays[0][x] = temp;
	arrays[1][y] = temp;
	//arrays[0][x]->next_x = NULL;
	//arrays[1][y]->next_y = NULL;
}

t_cell	*get_next_cell(t_cell *cell, char dir)
{
	if (dir == 'h')
		return (cell->next_x);
	if (dir == 'v')
		return (cell->next_y);
	else
		return (NULL);
}

int	get_param(t_cell *cell, char dir)
{
	if (dir == 'h')
		return (cell->x);
	if (dir == 'v')
		return (-cell->y);
	else
		return (-1);
}

t_cell	*get_obst(int coord, char dir, t_cell ***arrays)
{
	if (dir == 'h')
		return (arrays[1][coord]);
	if (dir == 'v')
		return (arrays[0][coord]);
	else
		return (NULL);
}

int	get_dist(int coord, int val, char dir, t_cell ***arrays)
{
	int		dist;
	t_cell	*obst;

	printf("inside get_dist");
	obst = get_obst(coord, dir, arrays);
	while (get_param(obst, dir) < val)
		obst = get_next_cell(obst, dir);
	dist = val - get_param(obst, dir);
	if (dist < 0)
		dist *= -1;
	printf(" - leaving get_dist\n");
	return (dist);
}
