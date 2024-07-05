/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:53:46 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 18:45:58 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
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

	len = count_blocks(str, bs);
	i = len - 1;
	block_list = malloc(sizeof(void *) * len);
	reminder = ft_strlen(str) % bs;
	if (block_list == NULL)
		return (NULL);
	if (reminder != 0)
	{
		block_list[i] = ft_strndup(str, ft_strlen(str) % bs);
		str += reminder;
		i--;
	}
	while (i >= 0)
	{
		block_list[i] = ft_strndup(str, bs);
		str += bs;
		i--;
	}
	return (block_list);
}

t_mag	*populate_mag(int order, int value, t_mag *next)
{
	t_mag	*mag;

	mag = malloc(sizeof(t_mag));
	if (mag == NULL)
		return (NULL);
	mag->order = order;
	mag->value = value;
	mag->next = next;
	return (mag);
}

t_mag	*chop_num(char *num)
{
	int		i;
	t_mag	*first_mag;
	char	**val_list;

	first_mag = NULL;
	val_list = split_blocks(num, 3);
	i = 0;
	while (i < count_blocks(num, 3))
	{
		if (val_list[i])
		{
			if (atoi(val_list[i]))
			{
				first_mag = populate_mag(i, ft_atoi(val_list[i]), first_mag);
				if (!first_mag)
					return (NULL);
			}
		}
		i++;
	}
	if (first_mag == NULL)
	{
		first_mag = populate_mag(0, 0, NULL);
	}
	if (!first_mag)
		return (NULL);
	cleanup_val_list(val_list);
	return (first_mag);
}
