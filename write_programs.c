/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_programs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:49:46 by icuz              #+#    #+#             */
/*   Updated: 2016/11/06 21:01:31 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	print_grid(int **grid)
{
	int i;
	int j;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < 8)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	gridblank(int **grid)
{
	int i;
	int j;

	i = -1;
	while (++i < 9)
	{
		j = 0;
		while (j < 9)
			grid[i][j++] = 0;
	}
}

int		**new_grid(void)
{
	int i;
	int **output;

	i = 0;
	output = (int **)malloc((9) * sizeof(int *));
	while (i < 9)
		output[i++] = (int *)malloc((9) * sizeof(int));
	gridblank(output);
	return (output);
}
