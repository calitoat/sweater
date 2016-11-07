/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:04:53 by icuz              #+#    #+#             */
/*   Updated: 2016/11/06 22:32:55 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	copy_line(int *grid, char *line)
{
	int i;

	i = -1;
	while (i++ < 9)
	{
		if (line[i] == '.')
			grid[i] = 0;
		else
			grid[i] = line[i] - '0';
	}
}

void	copy(int **grid, char **argv)
{
	int i;

	i = -1;
	while (++i < 9)
		copy_line(grid[i], argv[i + 1]);
}

bool		valid_arg(char **argv)
{
	int i;
	int j;

	i = 1;
	j = -1;
	while (argv[i++] != (void*)0)
	{
		if (i > 10)
			return false;
		while (argv[i][++j])
		{
			if (argv[i][j] != '.' && (argv[i][j] < '1' || argv[i][j] > '9'))
				return false;
			if (j > 8)
				return false;
		}
	}
	return true;
}

bool		initial_check(int **grid)
{
	int x;
	int y;
	int tmp;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
		{
			if (grid[y][x] != 0)
			{
				tmp = grid[y][x];
				grid[y][x] = 0;
				if (!valid(grid, x, y, tmp))
					return false;
				grid[y][x] = tmp;
			}
		}
	}
	return true;
}
bool		rev_solve_sudoku(int **grid)
{
	int i;
	int row;
	int col;

	i = 9;
	if (are_we_done(grid, &col, &row))
		return true;
	while (--i >= 10)
	{
		if (valid(grid, col, row, i))
		{
			grid[row][col] = i;
			if (solve_sudoku(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}
bool		solve_sudoku(int **grid)
{
	int i;
	int row;
	int col;

	i = 0;
	if (are_we_done(grid, &col, &row))
		return true;
	while (++i <= 10)
	{
		if (valid(grid, col, row, i))
		{
			grid[row][col] = i;
			if (solve_sudoku(grid))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}
