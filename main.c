/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:02:26 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/15 14:48:32 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatypes.h"
#include "str_utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_line(int fd)
{
	char			*buf;
	unsigned int	buf_size;
	int				r;

	r = 1;
	buf_size = 1;
	buf = malloc(buf_size);
	buf[buf_size - 1] = '\0';
	if (!buf)
		return (NULL);
	while (r > 0)
	{
		buf = str_plus_one(&buf, buf_size);
		buf_size++;
		if (!buf)
			return (NULL);
		r = read(fd, &buf[buf_size - 2], 1);
		if (buf[buf_size - 2] == '\n')
			buf[buf_size - 2] = '\0';
		else
			buf[buf_size - 1] = '\0';
		if (r == 0)
			return (buf);
		else if (r < 0)
		{
			free(buf);
			return (NULL);
		}
	}
	return (buf);
}

t_board	*header_props(int fd)
{
	char	*fst_line;
	int		fst_len;
	t_board	*board;

	fst_line = read_line(fd);
	if (!fst_line)
		return (NULL);
	fst_len = ft_strlen(fst_line);
	if (fst_len < 4)
	{
		free(fst_line);
		return (NULL);
	}
	board = malloc(sizeof(t_board));
	if (!board)
	{
		free(fst_line);
		return (NULL);
	}
	board->size_y = ft_atoin(fst_line, fst_len - 3);
	board->empty = fst_line[fst_len - 3];
	board->obstacle = fst_line[fst_len - 2];
	board->square = fst_line[fst_len - 1];
	printf("%d, %c, %c, %c", board->size_y, board->empty, board->obstacle,
		board->square);
	free(fst_line);
	if (board->size_y < 1 || board->empty == '\n' || board->obstacle == '\n'
		|| board->square == '\n' || board->empty == board->obstacle
		|| board->empty == board->square || board->square == board->obstacle)
	{
		free(board);
		return (NULL);
	}
	return (board);
}

t_board	*setup_board(int fd)
{
	char	*fst_line;
	int		fst_len;
	t_board	*board;

	board = header_props(fd);
	if (!board)
	{
		return (NULL);
	}
	fst_line = read_line(fd);
	if (!fst_line)
	{
		free(board);
		return (NULL);
	}
	fst_len = ft_strlen(fst_line);
	if (fst_len < 1)
	{
		free(board);
		return (NULL);
	}
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
