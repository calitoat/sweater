/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:17:08 by icuz              #+#    #+#             */
/*   Updated: 2016/11/06 21:26:51 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H

# define SUDOKU_H

# include <stdlib.h>

# include <unistd.h>

# include <stdbool.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	print_grid(int **grid);
void	gridblank(int **grid);
int		**new_grid(void);

bool		vertical(int **grid, int x, int num);
bool		horizontal(int **grid, int y, int num);
bool		sub_square(int **grid, int x, int y, int num);
bool		valid(int **grid, int x, int y, int num);
bool		are_we_done(int **grid, int *next_x, int *next_y);

void	copy_line(int *grid, char *line);
void	copy(int **grid, char **argv);
bool		valid_arg(char **argv);
bool		initial_check(int **grid);
bool		solve_sudoku(int **grid);

#endif
