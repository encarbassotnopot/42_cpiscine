/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoma-ba <ecoma-ba@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:08:13 by ecoma-ba          #+#    #+#             */
/*   Updated: 2024/05/01 19:53:08 by ecoma-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid_candidate(char *board, char candidate, int pos)
{
	int	current;

	current = 0;
	while (board[current] >= '0')
	{
		if (board[current] == candidate)
			return (0);
		if (board[current] - '0' + current == candidate - '0' + pos)
			return (0);
		if (board[current] - '0' - current == candidate - '0' - pos)
			return (0);
		current++;
	}
	return (1);
}

void	empty_board(char *board, int pos, int size)
{
	while (pos < size)
	{
		board[pos] = '\0';
		pos++;
	}
}

int	place_queen(char *board, int pos, int size)
{
	int		count;
	char	candidate;

	count = 0;
	candidate = '0';
	if (pos == size)
	{
		write(1, board, size);
		write(1, "\n", 1);
		return (1);
	}
	while (candidate < size + '0')
	{
		if (valid_candidate(board, candidate, pos))
		{
			board[pos] = candidate;
			count += place_queen(board, pos + 1, size);
			empty_board(board, pos, size);
		}
		candidate++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];

	empty_board(board, 0, 10);
	return (place_queen(board, 0, 10));
}
