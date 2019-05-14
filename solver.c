/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:03:39 by kmira             #+#    #+#             */
/*   Updated: 2019/05/12 19:13:47 by kmira            ###   ########.fr       */
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

int		count_pieces(t_tetrimino *tetrimino)
{
	int	result;

	result = 0;
	while (tetrimino[result].id != 0)
		result++;
	return (result);
}

int		solve_board(t_tetrimino * tetrimino, unsigned short *board, int board_size, int current_piece)
{
	int row;
	int col;

	if (current_piece == 26 || tetrimino[current_piece].id == 0)
		return (1);
	if (g_place_pruning[tetrimino[current_piece].type][0] == -1 && g_place_pruning[tetrimino[current_piece].type][1] == -1)
	{
		row = 0;
		col = 0;
	}
	else
	{
		row = g_place_pruning[tetrimino[current_piece].type][0];
		col = g_place_pruning[tetrimino[current_piece].type][1];
		// printf("Starting at: ROW %d and COL %d\n", row, col);
	}

	while (row + tetrimino[current_piece].height <= board_size)
	{
		while (col + tetrimino[current_piece].width <= board_size)
		{
			if (((*(u_int64_t *)(tetrimino[current_piece].mask) >> col) & *(u_int64_t *)&board[row]) == 0)
			{
				*(u_int64_t *)&board[row] = (*(u_int64_t *)&board[row]) ^ (*(u_int64_t *)tetrimino[current_piece].mask >> col);
				tetrimino[current_piece].row_loc = row;
				tetrimino[current_piece].col_loc = col;
				g_place_pruning[tetrimino[current_piece].type][0] = row;
				g_place_pruning[tetrimino[current_piece].type][1] = col;
				// printf("New board is of size %d with piece: %c\n", board_size, tetrimino[current_piece].id);
				// print_board(board);
				if (solve_board(tetrimino, board, board_size, current_piece + 1) == 1)
					return (1);
				*(u_int64_t *)&board[row] = (*(u_int64_t *)&board[row]) ^ (*(u_int64_t *)tetrimino[current_piece].mask >> col);
				g_place_pruning[tetrimino[current_piece].type][0] = 0;
				g_place_pruning[tetrimino[current_piece].type][1] = 0;
				tetrimino[current_piece].row_loc = 0;
				tetrimino[current_piece].col_loc = 0;
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (-1);
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
	while (solve_board(tetrimino, board, board_size, 0) == -1)
	{
		ft_bzero(board, sizeof(board));
		board_size++;
	}
	return (board_size);
}
