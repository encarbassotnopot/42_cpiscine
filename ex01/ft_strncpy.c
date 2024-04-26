/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:28:43 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/26 12:26:53 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int				is_terminated;
	unsigned int	index;

	is_terminated = 0;
	index = 0;
	while (index < n)
	{
		if (is_terminated)
		{
			*(dest + index) = '\0';
		}
		else
		{
			*(dest + index) = *(src + index);
			if (*(src + index) == '\0')
			{
				is_terminated = 1;
			}
		}
		index++;
	}
	return (dest);
}
