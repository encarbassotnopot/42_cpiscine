/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:58:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/15 14:35:40 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

// reads up to n decimal characters form a string, returns their value
// returns -1 if it finds a non-decimal charachter
int	ft_atoin(char *str, int n)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < n)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		result *= 10;
		result += *str - '0';
		str++;
		i++;
	}
	return (result);
}

// prints chars from a string until a nul terminator is found
void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

// prints a char
void	ft_putchar(char *c)
{
	write(1, c, 1);
}

// counts chars from a string until a nul terminator (that won't be counted)
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
	new = malloc(len + 1);
	if (!new)
	{
		free(*original);
		return (NULL);
	}
	ft_strcpy(new, *original);
	free(*original);
	return (new);
}
