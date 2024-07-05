/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:32:46 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/30 17:26:06 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	found_index;

	found_index = 0;
	if (*str == *to_find && *str == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		while (str[found_index] == to_find[found_index]
			&& to_find[found_index] != '\0')
		{
			found_index++;
		}
		if (to_find[found_index] == '\0')
		{
			return (str);
		}
		found_index = 0;
		str++;
	}
	return (0);
}
