/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:48:31 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/07 19:45:29 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	str_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	str_contains(char *str, char check)
{
	while (*str)
	{
		if (*str == check)
			return (1);
		str++;
	}
	return (0);
}

// terminates the split and creates the next one
// if given last = 1 creates the terminating split (null pointer)
void	next_split(char **str_group, int is_last, int str_idx, int ch_idx)
{
	if (str_group[str_idx][ch_idx] != '\0')
	{
		str_group[str_idx][ch_idx] = '\0';
		if (is_last)
			str_group[str_idx + 1] = 0;
		else
			str_group[str_idx + 1] = malloc(40);
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**str_group;
	int		str_idx;
	int		ch_idx;

	str_idx = 0;
	ch_idx = 0;
	str_group = malloc(40);
	str_group[str_idx] = malloc(40);
	str_group[str_idx][ch_idx] = '\0';
	while (*str != '\0')
	{
		if (str_contains(charset, *str))
		{
			next_split(str_group, 0, str_idx, ch_idx);
			ch_idx = 0;
			str_idx++;
		}
		else
		{
			str_group[str_idx][ch_idx] = *str;
			ch_idx++;
		}
		str++;
	}
	next_split(str_group, 1, str_idx, ch_idx);
	if (str_idx == 0 && ch_idx == 0)
		str_group[str_idx] = 0;
	return (str_group);
}
