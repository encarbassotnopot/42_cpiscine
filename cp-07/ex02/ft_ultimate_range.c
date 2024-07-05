/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:35:57 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/11 15:35:59 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	index;

	size = max - min;
	if (size <= 0)
		return (0);
	range = malloc(size * sizeof(int));
	if (range == 0)
	{
		errno = ENOMEM;
		return (0);
	}
	index = 0;
	while (index < size)
	{
		range[index] = min + index;
		index++;
	}
	return (range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	*range = ft_range(min, max);
	if (*range == NULL)
		return (0);
	return (max - min);
}
