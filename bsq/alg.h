/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:21:27 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/15 09:00:22 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"

t_b_props	*make_map(int x, int y);
t_cell		**make_cells(int x, int y);
void		put_obstacle(t_cell **map, int x, int j);
void		print_map(t_b_props *map_props, t_cell **map);
t_c_cont	get_cell_value(t_cell **map, int x, int y);
t_result	*get_result(t_b_props *map_props, t_cell **map, t_cell ***arrays);
t_cell		***set_cell_array(int x, int y);
void    update_result(t_result *res, int size, t_cell *obs, char dir);
t_cell  *get_next_cell(t_cell *cell, char dir);
int get_param(t_cell *cell, char c);
int	get_dist(int coord, int val, char dir, t_cell ***arrays);
int margin(int i, int j, char *dir, t_b_props *map_props);
void    append_me(int x, int y, t_cell ***arrays);
void    print_arrays(t_cell ***arrays, t_b_props *map);
int iterate_indexes(int *k, int *i, int *j, t_b_props *map_props);
