/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:32:46 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/29 19:42:44 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	iter_index;
	unsigned int	found_index;

	iter_index = 0;
	found_index = 0;
	while (str[iter_index] != '\0')
	{
		while ((&str[iter_index])[found_index] == to_find[found_index])
		{
			found_index++;
		}
		if (to_find[found_index] == '\0')
		{
			return (&str[iter_index]);
		}
		else
		{
			found_index = 0;
		}
		iter_index++;
	}
	return (0);
}
