/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:02:26 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/15 10:39:27 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include "alg.h"
#include <stdio.h>
#include <stdlib.h>

int	main()//int argc, char **argv)
{
	t_b_props	*map_props;
	t_cell		**map;
	t_cell		***arrays;
	t_result	*answer;
	//int i = 0;
	//int lol1 = 0;
	//int lol2 = 0;

	//argc++;
	//map_props = make_map(atoi(argv[1]), atoi(argv[2]));
	map_props = make_map(5, 5);
	map = make_cells(map_props->size_x, map_props->size_y);
	/*while (i < (atoi(argv[1]) * atoi(argv[2])) / 3)
	{
		lol1 = rand() % (atoi(argv[1]) - 1);
		lol2 = rand() % (atoi(argv[2]) - 1);
		put_obstacle(map, lol1, lol2);
		i++;
	}*/
	/*put_obstacle(map, 1, 3);
	put_obstacle(map, 2, 4);
	put_obstacle(map, 5, 6);
	put_obstacle(map, 5, 7);
	put_obstacle(map, 4, 3);
	put_obstacle(map, 6, 0);
	put_obstacle(map, 3, 3);
	put_obstacle(map, 1, 4);
	put_obstacle(map, 0, 1);
	put_obstacle(map, 2, 2);
	put_obstacle(map, 1, 7);
	put_obstacle(map, 2, 2);
	put_obstacle(map, 6, 3);
	put_obstacle(map, 7, 6);
	put_obstacle(map, 3, 1);
	put_obstacle(map, 4, 0);
	put_obstacle(map, 1, 0);
	put_obstacle(map, 3, 2);
	*/
	//put_obstacle(map, atoi(argv[3]), atoi(argv[4]));
	//put_obstacle(map, atoi(argv[5]), atoi(argv[6]));
	print_map(map_props, map);
	arrays = set_cell_array(map_props->size_x, map_props->size_y);
	print_arrays(arrays, map_props);
	answer = get_result(map_props, map, arrays);
	print_arrays(arrays, map_props);
}

