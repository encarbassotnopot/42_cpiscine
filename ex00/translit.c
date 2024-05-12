/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:44:42 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 02:48:07 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blocks.h"
#include "tdefs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void	cleanup(t_mag *mag)
{
	t_mag	*previous;

	while (mag->next)
	{
		previous = mag;
		mag = mag->next;
		free(previous);
	}
	free(previous);
}

int	main(int argc, char **argv)
{
	t_mag	*mag;
	t_mag	*start;

	if (argc != 2)
	{
		ft_putstr("Wrong number of args");
		return (1);
	}
	mag = chop_num(argv[1]);
	start = mag;
	while (mag->next)
	{
		printf("mag: %d, val: %d\n", mag->order, mag->value);
		mag = mag->next;
	}
	printf("mag: %d, val: %d\n", mag->order, mag->value);
	free(start);
}
