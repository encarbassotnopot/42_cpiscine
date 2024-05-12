/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 23:44:42 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 18:31:20 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blocks.h"
#include "cleanup.h"
#include "dict.h"
#include "tdefs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	process_dec_uni(unsigned int value, t_dict *dict)
{
	t_dict	*dict_start;

	dict_start = dict;
	while (value >= 0)
	{
		dict = dict_start;
		while (dict)
		{
			if (value == dict->value)
			{
				ft_putstr(dict->name);
				return (0);
			}
			else if (dict->next)
			{
				if (value < dict->next->value)
				{
					ft_putstr(dict->name);
					value -= dict->value;
					break ;
				}
				else
				{
					dict = dict->next;
				}
			}
			else
				return (1);
		}
	}
	return (1);
}

int	process_hundreds(unsigned int value, t_dict *dict)
{
	int	unit_hund;
	int	ret;

	ret = 0;
	unit_hund = value / 100;
	if (unit_hund == 0)
		return (0);
	ret += process_dec_uni(unit_hund, dict);
	ret += process_dec_uni(100, dict);
	return (ret);
}

// returns 0 if successful, 1 otherwise
int	print_val(unsigned int value, t_dict *dict)
{
	int	ret;

	ret = 0;
	ret += process_hundreds(value, dict);
	if (value % 100 != 0)
		ret += process_dec_uni(value % 100, dict);
	if (ret == 0)
		return (0);
	return (1);
}

// returns 0 if successful, 1 otherwise
int	print_mag(unsigned int order, t_dict *dict)
{
	if (order == 0)
		return (0);
	while (dict)
	{
		if (order == dict->value)
		{
			ft_putstr(dict->name);
			return (0);
		}
		dict = dict->next;
	}
	return (1);
}

// returns 0 if successful, 1 otherwise
int	print_block(t_mag *current, t_dict **vals, t_dict **mags)
{
	int	ret;

	ret = 0;
	ret += print_val(current->value, *vals);
	ret += print_mag(current->order, *mags);
	if (ret != 0)
		return (1);
	return (0);
}

void	transliterate(t_mag *mag)
{
	int		error_reported;
	t_dict	**mag_dict;
	t_dict	**val_dict;

	error_reported = 0;
	mag_dict = get_mag_dict();
	val_dict = get_val_dict();
	while (mag)
	{
		error_reported += print_block(mag, val_dict, mag_dict);
		mag = mag->next;
	}
	if (error_reported)
	{
		ft_putstr("Dict Error");
	}
	cleanup_dict(mag_dict);
	cleanup_dict(val_dict);
}

int	main(int argc, char **argv)
{
	t_mag	*mag;

	if (argc != 2)
	{
		ft_putstr("Wrong number of args");
		return (1);
	}
	if (!ft_str_is_numeric(argv[1]))
	{
		ft_putstr("Error: Non numeric string");
		return (1);
	}
	mag = chop_num(argv[1]);
	if (mag == NULL)
	{
		ft_putstr("Error: em moro");
		return (1);
	}
	transliterate(mag);
	cleanup_mag(mag);
}
