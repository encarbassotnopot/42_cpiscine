/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bernat_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:11:10 by bcanals-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/15 01:55:33 by bcanals-         ###   ########.fr       */
=======
/*   Updated: 2024/05/14 16:32:30 by bcanals-         ###   ########.fr       */
>>>>>>> bsq/m
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include <stdlib.h>
#include <stdio.h>

t_b_props	*make_map(int x, int y)
{
	t_b_props	*map;

	map = malloc(sizeof(t_b_props));
	map->size_x = x;
	map->size_y = y;
	return (map);
}

t_cell	**make_cells(int x, int y)
{
	t_cell	**fake_map;
	int		i;
	int		j;

	i = 0;
	fake_map = malloc(x * sizeof(t_cell *));
	while (i < x)
	{
		j = 0;
		fake_map[i] = malloc(y * sizeof(t_cell));
		while (j < y)
		{
			fake_map[i][j].x = j;
			fake_map[i][j].y = i;
			fake_map[i][j].content = empty;
			j++;
		}
		i++;
	}
	return (fake_map);
}

void	put_obstacle(t_cell **map, int x, int y)
{
	map[x][y].content = obstacle;
}

void	print_map(t_b_props *map_props, t_cell **map)
{
	int	i;
	int	j;

	i = map_props->size_y - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < map_props->size_x)
		{
<<<<<<< HEAD
			if (map[j][i].content == 1)
				printf("x ");
			else
				printf(". ");
=======
			printf("%i ", map[j][i].content);
>>>>>>> bsq/m
			j++;
		}
		printf("\n");
		i--;
	}
}

t_c_cont	get_cell_value(t_cell **map, int x, int y)
{
	return (map[x][y].content);
}
