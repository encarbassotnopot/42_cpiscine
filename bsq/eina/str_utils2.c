/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:58:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/15 16:49:28 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils1.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

char	*str_plus_one(char **original, unsigned int len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = malloc(len);
	if (!new)
	{
		free(*original);
		return (NULL);
	}
	ft_strcpy(new, *original);
	free(*original);
	return (new);
}
