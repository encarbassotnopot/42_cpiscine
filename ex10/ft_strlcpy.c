/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:45:38 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/26 14:55:47 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	*ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int index;

	index = 0;
	while (index < size - 1)
	{
		*(dest + index) = *(src + index);
		if (*(src + index) == '\0')
		{
			return (index);
		}
		index++;
	}

	*(dest + ++ index) = '\0';
	return (index);
}
