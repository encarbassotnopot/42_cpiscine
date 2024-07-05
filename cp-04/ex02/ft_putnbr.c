/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:06:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/30 17:12:37 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		index;
	char	to_write[10];

	index = 0;
	if (nb >= 0)
		nb *= -1;
	else
		write(1, "-", 1);
	while (index < 11)
	{
		to_write[index] = '0' - nb % 10;
		nb /= 10;
		if (nb == 0)
			break ;
		index++;
	}
	while (index >= 0)
	{
		write(1, &to_write[index], 1);
		nb /= 10;
		index--;
	}
}
