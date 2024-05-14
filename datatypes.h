/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:44:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/14 20:29:36 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

typedef enum			e_c_cont
{
	empty,
	obstacle
} t_c_cont;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_result
{
	int x;
	int y;
	int size;
}		t_result;

typedef struct s_cell
{
	int			x;
	int			y;
	struct s_cell		*next_x;
	struct s_cell		*next_y;
	enum e_c_cont	content;

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

