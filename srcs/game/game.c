/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:03:18 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/15 14:44:45 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		game(t_data *data)
{
		
	// printf("%d", data->col);
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 64*data->col, 64*data->row, "so_long");
    img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(data->mlx);
	
	return (1);
}