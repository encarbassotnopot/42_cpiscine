/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:58:36 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/01 13:01:04 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	factor;

	factor = 2;
	if (nb < 2)
		return (0);
	while (factor <= nb / 2)
	{
		if (nb % factor == 0)
			return (0);
		factor++;
	}
	return (1);
}
