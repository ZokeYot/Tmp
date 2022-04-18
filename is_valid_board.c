/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <zyot@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:42:52 by root              #+#    #+#             */
/*   Updated: 2022/04/18 17:43:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_board[5][5];
extern int	*g_condition;
extern int	*g_start_ptr[4];
extern int	g_offset[4][2];

int	compare_cond(int *ptr, int offset, int cond)
{
	int	i;
	int	seen;
	int	peak;

	i = 0;
	peak = 0;
	seen = 0;
	while (++i < 5)
	{		
		if (*ptr > peak)
		{
			peak = *ptr;
			++seen;
		}
		ptr += offset;
	}
	return (cond == seen);
}

int	is_valid_solution(void)
{
	int	cond;
	int	i;
	int	j;
	int	*ptr;

	cond = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		ptr = g_start_ptr[i];
		while (j < 4)
		{	
			if (!compare_cond(ptr, g_offset[i][0], g_condition[cond]))
				return (0);
			j++;
			cond++;
			ptr += g_offset[i][1];
		}
		++i;
	}
	return (1);
}
