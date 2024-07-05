/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bernat_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:38:32 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/14 23:06:25 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

int	margin_obs(int i, int j, char *dir, t_b_props *map_props)
{
	if (i == map_props->size_x - 1 && j == 0)
		return 0;
	if (i == map_props->size_x - 1)
		*dir = 'h';
	else
		*dir = 'v';
	return 1;
}

void	update_result(t_result *res, int size, t_cell *obs, char dir)
{
	res->size = size;
	res->x = obs->x;
	res->y = obs->y;
	if (dir == 'h')
		res->x += 1;
	else if (dir == 'v')
		res->y -= 1;
	return ;
}
