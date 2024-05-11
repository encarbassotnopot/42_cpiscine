/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:19:25 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/12 01:20:07 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strndup(char *src, int num);
int		count_blocks(char *str, int bs);
char	**split_blocks(char *str, int bs);
