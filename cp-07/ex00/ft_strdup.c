/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:05:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/09 13:29:23 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*new;

	len = 0;
	while (src[len])
		len++;
	new = malloc(len + 1);
	if (new == 0)
	{
		errno = ENOMEM;
		return (0);
	}
	len = 0;
	while (src[len])
	{
		new[len] = src[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}
