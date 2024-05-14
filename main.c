/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:02:26 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/14 21:11:10 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include "alg.h"
#include <stdio.h>
#include <stdlib.h>

int	min(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	main(int argc, char **argv)
{
	t_b_props	*map_props;
	t_cell		**map;
	t_cell		***arrays;
	t_result	*answer;

	argc++;
	map_props = make_map(atoi(argv[1]), atoi(argv[2]));
	map = make_cells(map_props->size_x, map_props->size_y);
	put_obstacle(map, atoi(argv[3]), atoi(argv[4]));
	put_obstacle(map, 3, 1);
	print_map(map_props, map);
	arrays = set_cell_array(map_props->size_x, map_props->size_y);
	answer = get_result(map_props, map, arrays);
}
