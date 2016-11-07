/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:04:53 by icuz              #+#    #+#             */
/*   Updated: 2016/11/06 19:39:56 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	copy_line(int *grid, char *line)
{
	int i;

	i = -1;
	while(i++ < 9)
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
	while(++i < 9)
		copy_line(grid[i], argv[i + 1]);
}

int		valid_arg(char **argv)
{
	int i;
	int j;

	i = 0;
	while(argv[i++] != '\0')
	{
		j = -1;
		if (i > 9)
			return (0);
		while(argv[i][++j])
		{
			if(argv[i][j] != '.' && (argv[i][j] < '1' || argv[i][j] > '9'))
				return (0);
			if(j > 8)
				return (0);
		}
	}
	return (1);
}

int		initial_check(int **grid)
{
	int x;
	int y;
	int tmp;

	y = -1;
	while(++y < 9)
	{
		x = -1;
		while(++x < 9)
		{
			if(grid[y][x] != 0)
			{
				tmp = grid[y][x];
				grid[y][x] = 0;
				if(!valid(grid, x, y, tmp))
					return (0);
				grid[y][x] = tmp;
			}
		}
	}
	return (1);
}

int solve_sudoku(int **grid)
{
	int i;
	int row;
	int col;

	i = 0;
	if(are_we_done(grid, &col, &row))
		return (1);
	while (++i <= 9)
	{
		if(valid(grid, col, row, i))
		{
			grid[row][col] = i;
			if (solve_sudoku(grid))
				return (1);
			grid[row][col] = 0;
		}
	}
	return (0);
}
