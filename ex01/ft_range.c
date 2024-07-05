/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:23:16 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/09 13:30:48 by ecoma-ba         ###   ########.fr       */
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
	range = malloc(size * 4);
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
