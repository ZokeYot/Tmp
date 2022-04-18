/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <zyot@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:38:08 by root              #+#    #+#             */
/*   Updated: 2022/04/18 17:38:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_grid(int grid[5][5])
{
	int	y;
	int	x;

	y = 0;
	while (++y < 5)
	{
		x = 0;
		while (++x < 5)
		{
			grid[y][x] += 48;
			write(1, &grid[y][x], 1);
			if (x != 5)
			{
				write(1, " ", 1);
			}
		}
		write(1, "\n", 1);
	}
}
