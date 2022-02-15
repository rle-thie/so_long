/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:03:18 by rle-thie          #+#    #+#             */
/*   Updated: 2022/02/15 16:24:20 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		game(t_data *data)
{
	// printf("%d", data->col);
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 64*data->col, 64*data->row, "so_long");
	data->img = mlx_xpm_file_to_image(data->mlx, "asset/wall.xpm", &data->img_size, &data->img_size);
	// mlx_xpm_to_image()
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	
	// mlx_destroy_image(data->mlx, data->img);
	mlx_loop(data->mlx);
	
	return (1);
}