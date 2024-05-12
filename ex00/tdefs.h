/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdefs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:20:37 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 09:05:41 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TDEFS_H
# define TDEFS_H

// t_mag holds the value of an order of magnitude (a power of 1000)
// order holds the order of magnitude (0 for 1, 1 for 1000 and so on)
// value represents the value of the order (for 123.000 would be 123)
// next holds a pointer to the next (lowest) order (or NULL if it desn't exist)
// ex: for 123.456 order=1 would be first with value=123 and point to t_mag
// for order 0. order 0 would have value=456 and next would hold NULL.
// if value of an order is 0, it can be skipped: in 123.000.456 t_mag of order
// 2 would point directly to t_mag of order 0.
typedef struct t_mag
{
	unsigned int	order;
	unsigned int	value;
	struct t_mag	*next;
}					t_mag;

typedef struct t_dict
{
	char			*name;
	unsigned int	value;
}					t_dict;
#endif
