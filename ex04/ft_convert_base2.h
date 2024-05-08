/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:01:30 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/08 11:14:33 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_radix(char *base);
int		get_str_pos(char *base, char ch);
int		base_to_dec(char *base, char *str, int radix);
void	ft_atoi_base(char *str, char *base, int *out, int radix);
void	dec_to_base(int nbr, char *base, char **dest, int radix);
