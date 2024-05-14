/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:44:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/14 10:57:57 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

enum			e_c_cont
{
	empty,
	obstacle
}

typedef struct s_cell
{
	int			x;
	int			y;
	s_cell		*next_x;
	s_cell		*next_y;
	e_c_cont	content;

}				t_cell;

typedef struct s_board
{
	int			size_x;
	int			size_y;
	char		empty;
	char		square;
	char		obstacle;
}				t_b_props;
#endif

//e_c_cont		get_cell_value(int x, int y);

