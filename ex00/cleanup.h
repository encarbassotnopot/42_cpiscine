/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:52:31 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 18:28:11 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H
# include "tdefs.h"

void	cleanup_dict(t_dict **dict);
void	cleanup_mag(t_mag *mag);
void	cleanup_val_list(char **val_list);
#endif
