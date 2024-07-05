/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:28:39 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/29 18:31:39 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	char			*start;

	index = 0;
	start = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && index < nb)
	{
		*dest = *src;
		src++;
		dest++;
		index++;
	}
	*dest = '\0';
	return (start);
}
