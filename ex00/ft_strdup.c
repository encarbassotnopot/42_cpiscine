/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:05:02 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/03 19:23:44 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*new;

	len = 0;
	while (src[len] != '\0')
		len++;
	new = malloc(len);
	len = 0;
	while (src[len] != '\0')
		new[len] = src[len];
	return (new);
}
