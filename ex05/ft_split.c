/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:48:31 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/08 11:22:27 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
// returns 1 if a new pointer is created
void	term_str(char **str_group, int str_idx, int ch_idx)
{
	if (str_group[str_idx][ch_idx] == '\0' && ch_idx == 0)
		str_group[str_idx] = 0;
	else
	{
		str_group[str_idx][ch_idx] = '\0';
		str_group[str_idx + 1] = 0;
	}
}

// returns 1 if a new pointer has been created, 0 if the same is used
// if given start = 1 it creates the first str (skiping checks)
int	init_str(char **str_group, int str_idx, int ch_idx, int start)
{
	if (start)
	{
		str_group[0] = malloc(40);
		str_group[0][0] = '\0';
		return (1);
	}
	if (str_group[str_idx][ch_idx] == '\0' && ch_idx == 0)
		return (0);
	if (str_group[str_idx][ch_idx] != '\0')
		str_group[str_idx][ch_idx] = '\0';
	str_group[str_idx + 1] = malloc(40);
	str_group[str_idx + 1][0] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_group;
	int		str_idx;
	int		ch_idx;

	str_idx = 0;
	ch_idx = 0;
	str_group = malloc(40);
	init_str(str_group, str_idx, ch_idx, 1);
	while (*str != '\0')
	{
		if (str_contains(charset, *str))
		{
			if (init_str(str_group, str_idx, ch_idx, 0))
			{
				ch_idx = 0;
				str_ix++;
			}
		}
		else
			str_group[str_idx][ch_idx++] = *str;
		str++;
	}
	term_str(str_group, str_idx, ch_idx);
	return (str_group);
}
