/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:30:15 by kmira             #+#    #+#             */
/*   Updated: 2019/05/13 17:35:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short g_place_pruning[26][2] =
{
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1},
	{-1, -1}
};

int		solve_board(t_tetrimino *tetrimino, char *board, int board_size)
{
	int	current_piece;
	int	row;
	int	col;

	current_piece = 0;
	while (tetrimino[current_piece].id != 0)
	{
		while (row < board_size)
		{
			while (col < board_size)
			{
				col++;
			}
			row++;
		}
	}
}

int		fill_board_with(t_tetrimino *tetrimino)
{
	unsigned short	board[16];
	int				board_size;
	int				pieces;

	board_size = 0;
	ft_bzero(board, sizeof(board));
	pieces = count_pieces(tetrimino);
	while (board_size * board_size < pieces * 4)
		board_size++;
	while (solve_board(tetrimino, board, board_size) == -1)
	{
		ft_bzero(board, sizeof(board));
		board_size++;
	}
	return (board_size);
}