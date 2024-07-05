/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:52:53 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/01 11:56:14 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	candidate;

	candidate = 0;
	if (nb < 0)
		return (0);
	while (candidate * candidate < nb)
		candidate++;
	if (candidate * candidate == nb)
		return (candidate);
	return (0);
}
