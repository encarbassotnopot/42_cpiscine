/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:48:31 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 19:54:46 by ecoma-ba         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

int	str_len(*str)
{

}

char	**ft_split(char *str, char *charset)
{
	// agafar len charset
	// buscar amb strstr
	// copiar aquí amb strcpy des de l'index que troba fins index+len charset
	// moure punter *str +index strstr + len charset
	// repetir fins al final
}
