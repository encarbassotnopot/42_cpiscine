/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:45:38 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/29 17:42:17 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	terminated;

	count = 0;
	terminated = 0;
	while (src[count] != '\0' || count < size)
	{
		if (count < size)
		{
			dest[count] = src[count];
		}
		else if (count == size && size != 0)
		{
			dest[count - 1] = '\0';
			terminated = 1;
		}
		if (src[count] == '\0')
		{
			(dest[count]) = (src[count]);
			return (count);
		}
		count++;
	}
	return (count);
}
