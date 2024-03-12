/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:28:20 by hwiemann          #+#    #+#             */
/*   Updated: 2024/03/12 12:22:05 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close()
{
	exit(0);
}

/* int	close_window(t_program *pro)
{
	//if(key)
	mlx_destroy_window(pro->mlx_pointer, pro->window);
	return(0);

}
*/


t_program	window()
{
	t_program	ptr;

	if(!(ptr.mlx_pointer = mlx_init(WIN_WIDTH, WIN_HEIGHT, "hello again", true)))
		exit(1);
	// if(!(ptr.window = /*mlx_new_window(ptr.mlx_pointer, WIN_WIDTH, WIN_HEIGHT, "HI")*/))
	// 	{
	// 		free(ptr.mlx_pointer);
	// 		exit(1);
	// 	}
//	free(ptr.mlx_pointer);
	mlx_loop(ptr.mlx_pointer);
//	mlx_hook(ptr.mlx_pointer, 17, 0, close_window(ptr.mlx_pointer), 0);
	return(ptr);
}

int	main()
{
	window();
	return(0);
}
