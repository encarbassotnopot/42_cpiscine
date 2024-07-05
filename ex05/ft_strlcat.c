/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:10:03 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/30 15:05:58 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	dest_len;

	index = 0;
	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
	{
		dest_len++;
	}
	while (src[index] != '\0' || index < size + dest_len)
	{
		if (index + dest_len + 1 < size)
		{
			(&dest[dest_len])[index] = src[index];
		}
		if (index + dest_len + 1 == size && size != 0)
		{
			(&dest[dest_len])[index] = '\0';
		}
		if (src[index] == '\0')
			break ;
		index++;
	}
	return (index + dest_len);
}
