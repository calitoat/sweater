/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_fuction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:35:25 by icuz              #+#    #+#             */
/*   Updated: 2016/11/06 22:13:26 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

bool	vertical(int **grid, int x, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[i++][x] == num)
			return false;
	}
	return true;
}

bool	horizontal(int **grid, int y, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[y][i++] == num)
			return false;
	}
	return true;
}

bool	sub_square(int **grid, int x, int y, int num)
{
	int	top_x;
	int	top_y;
	int initial_x;
	int initial_y;

	top_x = (x / 3) * 3;
	initial_x = top_x;
	initial_y = (y / 3) * 3;
	while (top_x < initial_x + 3)
	{
		top_y = (y / 3) * 3;
		while (top_y < initial_y + 3)
		{
			if (grid[top_y][top_x] == num)
				return false;
			top_y++;
		}
		top_x++;
	}
	return true;
}

bool	valid(int **grid, int x, int y, int num)
{
	if (vertical(grid, x, num) && horizontal(grid, y, num)
			&& sub_square(grid, x, y, num))
		return true;
	return false;
}

bool	are_we_done(int **grid, int *next_x, int *next_y)
{
	int y;
	int x;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
			if (grid[y][x] == 0)
			{
				*next_x = x;
				*next_y = y;
				return false;
			}
	}
	return true;
}
