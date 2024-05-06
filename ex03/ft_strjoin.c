/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:57:32 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 13:57:50 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(int size, int **strs, char *sep)
{
	char	*ptr;
	int		idx;
	int		bytes;
	int		sep_size;

	idx = 0;
	bytes = 0;
	sep_size = 0;
	while (idx < size)
	{
		ptr = strs[idx];
		while (*ptr)
		{
			bytes++;
			ptr++;
		}
		idx++;
	}
	while (*sep)
	{
		sep++;
		sep_size++;
	}
	return (bytes + sep_size * (strs - 1) + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		idx;

	if (size == 0)
	{
		str = malloc(1);
		*str = '\0';
		return (str);
	}
	str = malloc(get_size(size, strs, sep));
	// TODO
}
