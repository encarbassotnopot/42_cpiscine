/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:50:29 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/08 11:47:36 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		get_radix(char *base);
int		get_str_pos(char *base, char ch);
int		base_to_dec(char *base, char *str, int radix);
void	ft_atoi_base(char *str, char *base, int *out, int radix);
void	dec_to_base(int nbr, char *base, char **dest, int radix);

void	ft_putnbr_base(int nbr, char *base, char *dest, int radix)
{
	unsigned int	nbr_abs;
	int				index;

	nbr_abs = nbr;
	if (nbr < 0)
	{
		nbr_abs = ~(--nbr);
		*dest = '-';
		dest++;
	}
	index = 0;
	dec_to_base(nbr_abs, base, &dest, radix);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		*decimal;
	char	*result;
	int		radix;

	decimal = malloc(4);
	radix = get_radix(base_from);
	if (radix < 2)
		return (0);
	ft_atoi_base(nbr, base_from, decimal, radix);
	radix = get_radix(base_to);
	if (radix < 2)
		return (0);
	result = malloc(10);
	ft_putnbr_base(*decimal, base_to, result, radix);
	return (result);
}
