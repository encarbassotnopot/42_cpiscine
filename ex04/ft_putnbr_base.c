/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:28:48 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 16:06:40 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// reutrns the radix if base is valid (no +/- and no repeated chars). 0 on error
int	get_radix(char *base)
{
	char	seen[100];
	int		count;
	int		i;

	count = 0;
	while (base[count])
	{
		i = 0;
		if (base[count] == '+' || base[count] == '-')
			return (0);
		while (i <= count)
		{
			if (seen[i] == base[count])
				return (0);
			i++;
		}
		seen[count] = base[count];
		count++;
	}
	return (count);
}

void	parse_write(unsigned int nbr_abs, char *base, int radix)
{
	int		index;
	char	to_write[100];

	index = 0;
	while (index < 100)
	{
		to_write[index] = base[nbr_abs % radix];
		nbr_abs /= radix;
		if (nbr_abs == 0)
			break ;
		index++;
	}
	while (index >= 0)
	{
		write(1, &to_write[index], 1);
		index--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				radix;
	unsigned int	nbr_abs;

	radix = get_radix(base);
	nbr_abs = nbr;
	if (radix < 2)
		return ;
	if (nbr < 0)
	{
		nbr_abs = ~(--nbr);
		write(1, "-", 1);
	}
	parse_write(nbr_abs, base, radix);
}
