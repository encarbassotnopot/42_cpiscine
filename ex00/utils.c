/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:09:11 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 03:10:51 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	printf("atoi: %s\n", str);
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}

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

// returns a pointer to the reversed array, which it creates
char	**reverse_array(char **arr, int size)
{
	int		start;
	char	**out;

	start = 0;
	out = malloc(sizeof(void *) * size);
	if (out == NULL)
		return (NULL);
	while (start < size)
	{
		out[start] = arr[size - start - 1];
		start++;
	}
	return (out);
}
