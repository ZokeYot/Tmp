/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <zyot@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:37:35 by root              #+#    #+#             */
/*   Updated: 2022/04/18 17:44:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			g_board[5][5];
int			g_row_matrix[5][5];
int			g_col_matrix[5][5];
extern int	*g_condition;
int			*g_start_ptr[4];
int			g_offset[4][2];

int		fill_board(int row, int col);
int		is_valid_solution(void);
void	ft_print_grid(int grid[5][5]);

void	set_vars(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < 5)
	{
		while (++j < 5)
		{
			g_col_matrix[i][j] = 0;
			g_row_matrix[i][j] = 0;
		}
	}
	g_start_ptr[0] = &g_board[1][1];
	g_start_ptr[1] = &g_board[4][1];
	g_start_ptr[2] = &g_board[1][1];
	g_start_ptr[3] = &g_board[1][4];
	g_offset[0][0] = 5;
	g_offset[0][1] = 1;
	g_offset[1][0] = -5;
	g_offset[1][1] = 1;
	g_offset[2][0] = 1;
	g_offset[2][1] = 5;
	g_offset[3][0] = -1;
	g_offset[3][1] = 5;
}

int	fill_board_helper(int row, int col)
{
	int	val;

	val = 0;
	while (++val < 5)
	{
		if (g_row_matrix[row][val] || g_col_matrix[col][val])
			continue ;
		g_row_matrix[row][val] = 1;
		g_col_matrix[col][val] = 1;
		g_board[row][col] = val;
		if (fill_board(row, col + 1) == 1)
			return (1);
		g_row_matrix[row][val] = 0;
		g_col_matrix[col][val] = 0;
	}
	return (0);
}

int	fill_board(int row, int col)
{
	if (row == 5)
	{
		if (is_valid_solution())
		{		
			ft_print_grid(g_board);
			return (1);
		}
		return (0);
	}
	if (col == 5)
		return (fill_board(row + 1, 1));
	else
		return (fill_board_helper(row, col));
}

int	rush(void)
{
	set_vars();
	return (fill_board(1, 1));
}
