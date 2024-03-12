/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:29:27 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 15:52:20 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//#include <mlx.h>
#include "MLX42/MLX42.h"
#include "./libft/libft.h"

# define	WIN_HEIGHT	1080
# define	WIN_WIDTH	1920
# define	SSIZE		16


typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
	char	**map;
}	t_program;

char	**get_map(char *map);
int		check_map_ber(char *file);
mlx_image_t	*itsgiving_wall();




#endif
