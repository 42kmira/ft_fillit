/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:49:17 by kmira             #+#    #+#             */
/*   Updated: 2019/05/16 14:44:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern short g_place_pruning[27][2];

void	place_piece
	(t_tetrimino *tetrimino, unsigned short *board, int *row, int *col)
{
	tetrimino->row_loc = *row;
	tetrimino->col_loc = *col;
	*(u_int64_t *)&board[*row] =
		(*(u_int64_t *)&board[*row]) ^ (*(u_int64_t *)tetrimino->mask >> *col);
	g_place_pruning[tetrimino->type][0] = *row;
	g_place_pruning[tetrimino->type][1] = *col;
}

void	remove_piece
	(t_tetrimino tetrimino, unsigned short *board, int *row, int *col)
{
	*col = tetrimino.col_loc;
	*row = tetrimino.row_loc;
	*(u_int64_t *)&board[*row] =
		(*(u_int64_t *)&board[*row]) ^ (*(u_int64_t *)tetrimino.mask >> *col);
	g_place_pruning[tetrimino.type][0] = 0;
	g_place_pruning[tetrimino.type][1] = 0;
}

int		board_is_solved
	(int *current_piece, t_tetrimino *tetrimino, int *row, int *col)
{
	*current_piece = *current_piece + 1;
	if (*current_piece > 25 || !(tetrimino[*current_piece].id))
		return (1);
	else
	{
		*row = g_place_pruning[tetrimino[*current_piece].type][0];
		*col = g_place_pruning[tetrimino[*current_piece].type][1];
		*col = *col - 1;
	}
	return (0);
}
