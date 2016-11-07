/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:59:45 by icuz              #+#    #+#             */
/*   Updated: 2016/11/06 22:23:36 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	main(int argc, char **argv)
{
	int **grid;

	if (argc != 10 || !valid_arg(argv))
	{
		ft_putstr("error.\n");
		return (0);
	}
	else
	{
	grid = new_grid();
	copy(grid, argv);
	if (initial_check(grid) && solve_sudoku(grid))
		print_grid(grid);
	else
		ft_putstr("error.\n");
	return (0);
}
}
