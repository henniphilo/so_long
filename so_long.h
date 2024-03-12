/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:29:27 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 12:16:11 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//#include <mlx.h>
#include "MLX42/MLX42.h"
#include "./libft/libft.h"

#define	WIN_HEIGHT	1080
#define	WIN_WIDTH	1920


typedef struct s_program
{
	void *mlx_pointer;
	void *window;
}	t_program;

#endif
