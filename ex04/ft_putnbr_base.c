/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:28:48 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/04/30 19:16:28 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base)
{
	int		index;
	char	to_write[100];
	int		radix;

	index = 0;
	radix = 1;
	while (base[radix] != '\0')
		radix++;
	if (radix > 2)
	{
		if (nbr >= 0)
			nbr *= -1;
		else
			write(1, "-", 1);
		while (index < 100)
		{
			to_write[index] = base[-nbr % radix];
			nbr /= radix;
			if (nbr == 0)
				break ;
			index++;
		}
		while (index >= 0)
		{
			write(1, &to_write[index], 1);
			index--;
		}
	}
}
