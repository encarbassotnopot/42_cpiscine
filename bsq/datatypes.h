/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:44:02 by ecoma-ba          #+#    #+#             */
<<<<<<< HEAD:bsq/datatypes.h
/*   Updated: 2024/05/15 02:51:33 by bcanals-         ###   ########.fr       */
=======
/*   Updated: 2024/05/15 16:22:18 by ecoma-ba         ###   ########.fr       */
>>>>>>> bsq/us-odio:datatypes.h
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

<<<<<<< HEAD:bsq/datatypes.h
typedef enum			e_c_cont
{
	empty,
	obstacle
} t_c_cont;

typedef struct s_result
{
	int x;
	int y;
	int size;
}		t_result;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_cell
{
	int			x;
	int			y;
	struct s_cell		*next_x;
	struct s_cell		*next_y;
	enum e_c_cont	content;
=======
typedef enum e_c_cont
{
	empty,
	obstacle
}					t_c_cont;

typedef struct s_cell
{
	int				x;
	int				y;
	struct s_cell	*next_x;
	struct s_cell	*next_y;
	t_c_cont		content;
>>>>>>> bsq/us-odio:datatypes.h

}					t_cell;

typedef struct s_board
{
	int				size_x;
	int				size_y;
	char			empty;
	char			square;
	char			obstacle;
	int				*board;
}					t_board;
#endif

// e_c_cont		get_cell_value(int x, int y);
