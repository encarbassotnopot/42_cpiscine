/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:21:49 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/13 11:24:15 by ecoma-ba         ###   ########.fr       */
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
	int					i;
	struct s_stock_str	*out;

	i = 0;
	out = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (out == NULL)
		return (NULL);
	while (i < ac)
	{
		out[i].size = ft_strlen(av[i]);
		out[i].str = av[i];
		out[i].copy = ft_strdup(av[i]);
		if (out[i].copy == NULL)
			return (NULL);
		i++;
	}
	out[i].str = 0;
	return (out);
}
