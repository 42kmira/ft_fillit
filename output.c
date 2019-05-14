/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:55:45 by kmira             #+#    #+#             */
/*   Updated: 2019/05/13 15:35:38 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		write_piece(t_tetrimino piece, char *board_str, int board_size)
{
	int	bit;
	int	i;

	bit = 1 << 15;
	i = 0;
	while (i < 4)
	{
		if (piece.mask[0] & bit)
			board_str[i + piece.col_loc +
			((board_size + 1) * (piece.row_loc + 0))] = piece.id;
		if (piece.mask[1] & bit)
			board_str[i + piece.col_loc +
			((board_size + 1) * (piece.row_loc + 1))] = piece.id;
		if (piece.mask[2] & bit)
			board_str[i + piece.col_loc +
			((board_size + 1) * (piece.row_loc + 2))] = piece.id;
		if (piece.mask[3] & bit)
			board_str[i + piece.col_loc +
			((board_size + 1) * (piece.row_loc + 3))] = piece.id;
		bit = bit >> 1;
		i++;
	}
}

void			print_solution_of(t_tetrimino *tetriminos, int board_size)
{
	char	board_str[16 * 16];
	int		num_pieces;
	int		i;

	ft_memset(board_str, '.', 16 * 16);
	i = -1;
	while (++i < board_size)
		board_str[(i * (board_size + 1)) + board_size] = '\n';
	i = -1;
	num_pieces = count_pieces(tetriminos);
	while (++i < num_pieces)
		write_piece(tetriminos[i], board_str, board_size);
	write(1, board_str, board_size * (board_size + 1));
}
