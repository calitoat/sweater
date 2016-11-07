/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:17:08 by icuz              #+#    #+#             */
/*   Updated: 2016/11/06 18:55:37 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SUDOKU_H
# define SUDOKU_H
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	print_grid(int **grid);
void	gridblank(int **grid);
int		**new_grid(void);

int		veritcal(int **grid, int x, int num);
int		horizontal(int **grid, int y, int num);
int		sub_square(int **grid, int x, int y, int num);
int		valid(int **grid, int x, int y, int num);
int		are_we_done(int **grid, int *next_x, int *next_y);

void	copy_line(int *grid, char *line);
void	copy(int **grid, char **argv);
int		valid_arg(char **argv);
int		initial_check(int **grid);
int		solve_sudoku(int **grid);

#endif
