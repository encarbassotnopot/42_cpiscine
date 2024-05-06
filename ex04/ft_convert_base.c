/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:01:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/06 17:32:47 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// returns index of the first ocurrence of ch in the base string.
// -1 if not found
int	get_str_pos(char *base, char ch)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	convert_base(char *base, char *str, int radix)
{
	int	val;
	int	result;

	result = 0;
	while (*str)
	{
		val = get_str_pos(base, *str);
		if (val == -1)
			break ;
		result *= radix;
		result += val;
		str++;
	}
	return (result);
}

ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	radix;
	int	*out

	sign = 1;
	radix = get_radix(base);
	if (radix < 2)
	{
		out = 0;
		return ;
	}
	while (*str == ' ' || (*str > 8 && *str < 14))
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = convert_base(base, str, radix);
	*out = (sign * result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
}
