/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:02:26 by bcanals-          #+#    #+#             */
/*   Updated: 2024/05/14 10:19:53 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "BSQ.h"

int main (int argc, char **argv)
{
	int fd1;
	int fd1_r;
	struct info_line info;
	
	fd1 = open(argv[1], O_RDONLY);
	printf("fd1 = %d\n", fd1);
	fd1_r = read(fd1, &info.lines, 1);
	ft_putstr("flag 1\n");
	fd1_r  = read(fd1, &info.empty, 1);
	ft_putstr("flag 2\n");
	fd1_r = read(fd1, &info.obstacle, 1);
	ft_putstr("flag 3\n");
	fd1_r = read(fd1, &info.full, 1);
	ft_putstr("flag 4\n");
	fd1_r  = read(fd1, &info.new_line, 1);
	ft_putstr("flag 5\n");
	printf("read:\n\tlines = %c\n\tempty = %c\n\tobstc = %c\n\tfull  = %c",
			info.lines, info.empty, info.obstacle, info.full);
	if (info.new_line == '\n')
		ft_putstr("\tEOL correct!");
	else
		ft_putstr("\tEOL NOT correct :(");
	close(fd1);
	argc++;
}
