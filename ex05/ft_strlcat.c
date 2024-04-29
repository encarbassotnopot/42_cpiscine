/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:10:03 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/29 21:07:19 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_len;

	index = 0;
	dest_len = 0;
	printf("---\nd:%s, i:%s, s:%d\n", dest, src, size);
	while (*dest != '\0')
	{
		dest++;
		dest_len++;
	}
	while (src[index] != '\0' || index + dest_len <= size)
	{
		printf("\nd:%c, i:%c, s:%d\n", dest[index], src[index], index);
		if (src[index] == '\0')
		{
			dest[index] = src[index];
			return (index);
		}
		else if (index + dest_len == size && size != 0)
		{
			dest[index] = '\0';
			return (index);
		}
		if (index + dest_len < size)
		{
			dest[index] = src[index];
		}
		index++;
	}
	return (index);
}
