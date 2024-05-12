/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:31:21 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 18:29:28 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdefs.h"
#include <stdlib.h>

void	cleanup_dict(t_dict *dict)
{
	t_dict	*previous;

	while (dict->next)
	{
		previous = dict;
		dict = dict->next;
		free(previous);
	}
	free(dict);
}

void	cleanup_mag(t_mag *mag)
{
	t_mag	*previous;

	while (mag->next)
	{
		previous = mag;
		mag = mag->next;
		free(previous);
	}
	free(mag);
}

void	cleanup_val_list(char **val_list)
{
	int i = 0;
	while (val_list[i])
	{
		free(val_list[i]);
		i++;
	}
	free(val_list);
}
