/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:21:10 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/02 15:09:35 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

void	gen_word_order(char **array, int *ordered, int len)
{
	int	i;
	int	j;
	int	largest;

	i = len - 1;
	j = 1;
	while (i > 0)
	{
		largest = 0;
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(array[j], array[largest]) > 0)
			{
				largest = j;
				printf("%s < %s\n", array[j], array[j + 1]);
			}
			j++;
		}
		ordered[i] = largest;
		i--;
	}
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	largest[argc];

	i = 1;
	gen_word_order(argv, largest, argc);
	while (i < argc)
	{
		if (i != 0)
			ft_putstr(argv[largest[i]]);
		i++;
	}
	return (0);
}
