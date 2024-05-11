/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:53:46 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 01:34:10 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tdefs.h"
#include "utils.h"
#include <stdlib.h>

char	*ft_strndup(char *src, int num)
{
	int		len;
	char	*new;

	len = 0;
	new = malloc(num + 1);
	if (new == 0)
	{
		return (0);
	}
	while (src[len] && num)
	{
		new[len] = src[len];
		len++;
		num--;
	}
	new[len] = '\0';
	return (new);
}

// counts into how many blocks a string would be split by split_blocks
int	count_blocks(char *str, int bs)
{
	int	len;
	int	block_num;

	len = ft_strlen(str);
	block_num = (len / bs);
	if (len % bs != 0)
		block_num++;
	return (block_num);
}

// splits a str into blocks of size bs. the blocks are filled "from the end",
// so the first block's size might be lower than bs.
// returns an array to the split blocks, starting from the start of the string
char	**split_blocks(char *str, int bs)
{
	int		len;
	char	**block_list;
	int		i;
	int		reminder;

	i = 1;
	len = count_blocks(str, bs);
	block_list = malloc(sizeof(void *) * len);
	reminder = ft_strlen(str) % bs;
	if (block_list == NULL)
		return (NULL);
	if (reminder != 0)
	{
		block_list[0] = ft_strndup(str, ft_strlen(str) % bs);
		str += reminder;
	}
	else
		i = 0;
	while (i < len)
	{
		block_list[i] = ft_strndup(str, bs);
		str += bs;
		i++;
	}
	return (block_list);
}

/*
t_mag	*chop_num(char *num)
{
	int		i;
	t_mag	*first_mag;

	i = len - 1;
	while (i >= 0)
	{
		atoi(num[i], 3);
	}
}*/
