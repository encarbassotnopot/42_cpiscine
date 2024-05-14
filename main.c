/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:02:26 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/14 18:41:33 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include "str_utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_board	*setup_board(int fd)
{
	char			*buf;
	unsigned int	buf_size;

	buf_size = 1;
	buf = malloc(buf_size);
	if (!buf)
		return (NULL);
	while (buf[buf_size - 1] != '\n')
	{
		ft_putchar(&buf[buf_size - 1]);
		buf = str_plus_one(&buf, buf_size);
		ft_putchar(&buf[buf_size]);
		buf_size++;
		if (!*buf)
		{
			ft_putstr("em moro\n");
			return (NULL);
		}
		if (read(fd, &buf[buf_size - 1], 1) < 1)
		{
			ft_putstr("em mato\n");
			return (NULL);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_board	*board;

	i = 0;
	argv++;
	argc--;
	if (argc == 0)
	{
		fd = 0;
	}
	while (i < argc || (i == 0 && argc == 0))
	{
		if (argc != 0)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				ft_putstr("file error\n");
				i++;
				continue ;
			}
		}
		board = setup_board(fd);
		if (!board)
			ft_putstr("map error\n");
		if (fd != 0)
		{
			if (close(fd) == -1)
				ft_putstr("error closing file\n");
		}
		i++;
	}
}
