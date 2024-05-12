/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:44:42 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 09:50:23 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blocks.h"
#include "tdefs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void	transliterate(t_mag *head)
{
	t_dict	mag_dict;
	t_dict	val_dict;
	t_mag	*previous;

	mag_dict = get_mag_dict();
	val_dict = get_val_dict();
	while (mag->next)
	{
		previous = head;
		head = head->next;
	}
}

void	cleanup(t_mag *mag)
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

int	main(int argc, char **argv)
{
	t_mag	*mag;

	if (argc != 2)
	{
		ft_putstr("Wrong number of args");
		return (1);
	}
	mag = chop_num(argv[1]);
	cleanup(mag);
}
