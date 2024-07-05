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

void	join_with_sep(int size, char **strs, char *sep, char *out)
{
	int		index;

	ft_strcpy(&out, strs[0]);
	index = 1;
	while (index < size)
	{
		ft_strcpy(&out, sep);
		ft_strcpy(&out, strs[index]);
		index++;
	}
	*out = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;

	if (size == 0)
	{
		result = malloc(1);
		if (result == 0)
		{
			return (0);
		}
		*result = '\0';
		return (result);
	}
	result = malloc(get_size(size, strs, sep) + 1);
	if (result == 0)
	{
		return (0);
	}
	join_with_sep(size, strs, sep, result);
	return (result);
}
