/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:03:39 by bcanals-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/15 10:30:52 by bcanals-         ###   ########.fr       */
=======
/*   Updated: 2024/05/14 19:17:43 by bcanals-         ###   ########.fr       */
>>>>>>> bsq/m
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>

<<<<<<< HEAD
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
=======
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
>>>>>>> bsq/m
}

t_cell	*get_next_cell(t_cell *cell, char dir)
{
	if (dir == 'h')
		return (cell->next_x);
	if (dir == 'v')
		return (cell->next_y);
	else
<<<<<<< HEAD
		return (NULL);
=======
		return NULL;
>>>>>>> bsq/m
}

int	get_param(t_cell *cell, char dir)
{
	if (dir == 'h')
		return (cell->x);
	if (dir == 'v')
<<<<<<< HEAD
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
=======
	{
		if (cell->y == -1)
			return (1);
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
>>>>>>> bsq/m
{
	int		dist;
	t_cell	*obst;

<<<<<<< HEAD
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
=======
	obst = get_obst(coord, dir, arrays);
	while (get_param(obst, dir) < val)
	{
		obst = get_next_cell(obst, dir);
	}
	dist = val - get_param(obst, dir);
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
>>>>>>> bsq/m
