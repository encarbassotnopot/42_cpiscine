/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:19:25 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 02:18:06 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCKS_H
# define BLOCKS_H
# include "tdefs.h"

char	*ft_strndup(char *src, int num);
int		count_blocks(char *str, int bs);
char	**split_blocks(char *str, int bs);
t_mag	*populate_mag(int order, int value, t_mag *next);
t_mag	*chop_num(char *num);
#endif
