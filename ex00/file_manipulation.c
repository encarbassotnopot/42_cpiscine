/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldoma <rbaldoma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:50:49 by rbaldoma          #+#    #+#             */
/*   Updated: 2024/05/12 16:52:30 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_copy_value(char *ptr, char value[20])
{
	int	length;

	length = 0;
	while (*ptr != '\n' && *ptr != '\0' && length < 19)
		value[length++] = *ptr++;
	value[length] = '\0';
	return (ptr);
}

char	*ft_skip_spaces(char *ptr)
{
	while (*ptr == ' ')
		ptr++;
	return (ptr);
}

int	ft_get_values(char *buffer, ssize_t bytes_read, char values[41][20],
		int index)
{
	char	*ptr;
	char	*end;
	char	*to_search;

	ptr = buffer;
	end = buffer + bytes_read;
	while (ptr < end)
	{
		to_search = ft_strchr(ptr, ':');
		if (to_search != NULL)
		{
			ptr = to_search + 1;
			ptr = ft_skip_spaces(ptr);
			ptr = ft_copy_value(ptr, values[index]);
			index++;
		}
		else
			break ;
	}
	return (index);
}

int	ft_read_values(int dict, char values[41][20])
{
	char	buffer[1024];
	int		index;
	ssize_t	bytes_read;

	index = 0;
	while ((bytes_read = read(dict, buffer, sizeof(buffer))) > 0)
		index = ft_get_values(buffer, bytes_read, values, index);
	return (index);
}
