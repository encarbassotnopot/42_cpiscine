/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:21:49 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/11 19:43:47 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <sys/errno.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		len;

	len = ft_strlen(src);
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		// malloc sizeoff struct
		// struct -> len = strlen
		// struct str = str[i]
		// struct copy = strdup str
	}
}
