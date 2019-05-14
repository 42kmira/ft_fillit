/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:18:38 by kmira             #+#    #+#             */
/*   Updated: 2019/05/13 15:22:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_STRUCTS_H
# define FILLIT_STRUCTS_H

typedef struct			s_piece
{
	unsigned short		mask[4];
	int					type;
	int					width;
	int					height;
	int					row_loc;
	int					col_loc;
	int					id;
}						t_tetrimino;

enum					e_myerrors {
	INVALID_FILE_FORMAT = -2,
	INVALID_PIECE_FORMAT = -3,
};

#endif
