/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:33:15 by kmira             #+#    #+#             */
/*   Updated: 2019/05/16 20:43:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int aa, char **args)
{
	int			fd;
	const char	*file;
	t_tetrimino	tetriminos[MAX_TETRIMINO_PIECES];
	int			board_size;

	if (aa != 2)
		EXIT("fillit: usage");
	file = args[1];
	fd = open(file, O_RDONLY);
	if (fd == INVALID_FILE)
		EXIT("usage: File does not exist");
	if (begin_reading(fd, tetriminos) == -1)
	{
		if (errno == INVALID_FILE_FORMAT)
			EXIT("error");
		else if (errno == INVALID_PIECE_FORMAT)
			EXIT("error");
		else
			EXIT("error");
	}
	board_size = fill_board_with(tetriminos);
	print_solution_of(tetriminos, board_size);
	return (0);
}
