/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/11 16:35:03 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close()
{
	exit(0);
}

t_program	window()
{
	t_program	ptr;

	if(!(ptr.mlx_pointer = mlx_init()))
		exit(1);
	if(!(ptr.window = mlx_new_window(ptr.mlx_pointer, WIN_WIDTH, WIN_HEIGHT, "HI")))
		{
			free(ptr.mlx_pointer);
			exit(1);
		}
	free(ptr.mlx_pointer);

//	mlx_hook(ptr.reference, 17, 0, ft_close, 0);
	return(ptr);
}

int	main()
{
	window();
	return(0);
}
