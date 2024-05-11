/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:26:31 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/11 19:39:13 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str ++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (par == 0)
		return ;
	while (par -> str != 0)
	{
		ft_putnbr(par -> size);
		ft_putstr(par -> str);
		ft_putstr(par -> copy);
		par++;
	}
}
