/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:44:42 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 01:31:12 by ecoma-ba         ###   ########.fr       */
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
	char	**bl;

	if (argc != 2)
	{
		ft_putstr("Wrong number of args");
		return (1);
	}
	bl = split_blocks(argv[1], 3);
	for (int i = 0; i < count_blocks(argv[1], 3); i++)
		printf("%s\n", bl[i]);
}
