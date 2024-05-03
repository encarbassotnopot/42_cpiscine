/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:23:16 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/03 19:41:04 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	index;

	size = max - min;
	if (size < 0)
		return (0);
	range = malloc(size);
	index = 0;
	while (index < size)
	{
		range[index] = min + index;
		index++;
	}
	return range;
}
