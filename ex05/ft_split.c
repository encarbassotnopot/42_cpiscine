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
void term_str(char **str_group, int str_idx, int ch_idx)
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
int	init_str(char **str_group, int str_idx, int ch_idx)
{
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
	int		out;

	str_idx = 0;
	ch_idx = 0;
	str_group = malloc(40);
	str_group[str_idx] = malloc(40);
	str_group[str_idx][ch_idx] = '\0';
	while (*str != '\0')
	{
		if (str_contains(charset, *str))
		{
			out = init_str(str_group, str_idx, ch_idx);
			if(out == 1)
			{
				ch_idx = 0;
				str_idx++;
			}
		}
		else
		{
			str_group[str_idx][ch_idx] = *str;
			ch_idx++;
		}
		str++;
	}
	term_str(str_group, str_idx, ch_idx);
	return (str_group);
}
/**
int main()
{
	char *str = ".,.,.,...,,,hello.,.,,,,..,,,world";
	char *str2 = ".,.,.,...,,,.,.,,,,..,,,.,.,.,.,,.";
	char *str3 = "hello";
	char *set = ",.";
	char **grp = ft_split(str, set);

		printf("%s\n", grp[0]);
	for (int i = 0; i++; grp[i] != 0)
	{
		printf("%s\n", grp[i]);
	}
}*/
