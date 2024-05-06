/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:57:08 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 18:31:49 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	index;
	int	*ptr;

	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	ptr = malloc(size);
	if (ptr == 0)
		return (-1);
	*range = ptr;
	index = 0;
	while (index < size)
	{
		*(*range + index) = min + index;
		index++;
	}
	return (size);
}
