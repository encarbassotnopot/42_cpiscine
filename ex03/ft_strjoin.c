/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:57:32 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/09 13:56:21 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>

int	get_size(int size, char **strs, char *sep)
{
	char	*ptr;
	int		idx;
	int		bytes;
	int		sep_size;

	idx = 0;
	bytes = 0;
	sep_size = 0;
	while (idx < size)
	{
		ptr = strs[idx];
		while (*ptr)
		{
			bytes++;
			ptr++;
		}
		idx++;
	}
	while (*sep)
	{
		sep++;
		sep_size++;
	}
	return (bytes + sep_size * (size - 1) + 1);
}

void	ft_strcpy(char **dest, char *src)
{
	while (*src != '\0')
	{
		**dest = *src;
		*dest += 1;
		src++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*start;
	char	**bookmark;
	int		index;

	if (size == 0)
	{
		start = malloc(1);
		if (start == 0)
		{
			errno = ENOMEM;
			return (0);
		}
		*start = '\0';
		return (start);
	}
	start = malloc(get_size(size, strs, sep) + 1);
	bookmark = malloc(8);
	if (start == 0 || bookmark == 0)
	{
		errno = ENOMEM;
		return (0);
	}
	*bookmark = start;
	ft_strcpy(bookmark, strs[0]);
	index = 1;
	while (index < size)
	{
		ft_strcpy(bookmark, sep);
		ft_strcpy(bookmark, strs[index]);
		index++;
	}
	**bookmark = '\0';
	return (start);
}
