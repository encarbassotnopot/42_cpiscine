/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manipulation.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldoma <rbaldoma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:28:49 by rbaldoma          #+#    #+#             */
/*   Updated: 2024/05/12 14:17:20 by rbaldoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

char	*ft_strchr(const char *str, int c);
char	*ft_copy_value(char *ptr, char value[20]);
char	*ft_skip_spaces(char *ptr);
int		ft_get_values(char *buffer, ssize_t bytes_read, char values[40][20], int index);
int		read_values(int dict, char values[40][20]);

