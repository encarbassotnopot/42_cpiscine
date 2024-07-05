/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:21:10 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/02 18:58:50 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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
	int	iter_limit;
	int	j;

	j = 0;
	while (j < len)
	{
		ordered[j] = j;
		j++;
	}
	j = 0;
	iter_limit = len - 1;
	while (iter_limit > 0)
	{
		j = 0;
		while (j < iter_limit)
		{
			if (ft_strcmp(array[ordered[j]], array[ordered[j + 1]]) > 0)
				ft_swap(&ordered[j], &ordered[j + 1]);
			j++;
		}
		iter_limit--;
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
	int	largest[50];

	i = 0;
	argv++;
	argc--;
	if (argc > 0)
		gen_word_order(argv, largest, argc);
	while (i < argc)
	{
		ft_putstr(argv[largest[i]]);
		i++;
	}
	return (0);
}
